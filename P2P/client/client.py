import socket, json, pickle, struct, threading, subprocess, sys, os, logging

logging.basicConfig(level=logging.DEBUG, filename="client.log", format='%(asctime)s %(message)s',)

class client:

	myaddr = "127.0.0.1"
	buffer_size = 516
	root_dir = "repositories/"
	working_dir = ""

	def __init__(self, server_host="127.0.0.1", host="127.0.0.1", udp_port=65000, tcp_serv_port=64000, tcp_port=65432):
		
		"""
		Everytime you run the client it sends a dictionary with 
		the list of local repositories, therefore the server 
		can update the index of peers and their repos.
		Also runs a daemon for receive tcp request from other
		peers, and a git daemon so other peers may clone 
		repositories if they can't connect to the server or 
		clone a local repository from the peer.
		"""

		self.server_udp_addr = (server_host, udp_port)
		self.server_tcp_addr = (server_host, tcp_serv_port)
		self.tcp_addr = (host, tcp_port)
		
		tcp_thread = threading.Thread(target=self.tcp_req, args=(self.tcp_addr, ), daemon=True)
		tcp_thread.start()
		git_thread = threading.Thread(target=self.git_daemon, daemon=True)
		git_thread.start()

		try:
			with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as udp_socket:
				udp_socket.settimeout(1)
				dict = {"repos": self.get_repos()}
				packet = self.set_packet(1, dict)
				print(self.server_udp_addr)
				udp_socket.sendto(packet, self.server_udp_addr)
				udp_socket.sendto(packet, ("192.168.1.78", 65000))
				received = udp_socket.recvfrom(516)
				self.handle_packet(received[0])
				self.myaddr = host

		except Exception as e:
			self.myaddr = host
			logging.debug(e)
			print("Can't update the repositories")
		
	def tcp_req(self, tcp_addr):
		with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as tcp_socket:
			tcp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
			tcp_socket.bind(tcp_addr)
			tcp_socket.listen(10)
			while(True):
				conn, addr = tcp_socket.accept()
				thread = threading.Thread(target=self.handle_tcp_req, args=(conn, ))
				thread.start()

	def handle_tcp_req(self, conn):
		try:
			while(True):
				data = conn.recv(516)
				code = struct.unpack("!H", data[0:2])
				if(code[0] == 3):
					repos = self.get_repos()
					packet = self.set_packet(6, repos)
					conn.sendall(packet)
				# elif(code[0] == 4):
				# 	thread = threading.Thread(target=self.git_daemon)
				# 	thread.start()
				# 	packet = self.set_packet(0, "git daemon up")
				# 	conn.sendall(packet)
				else:
					msg = "Unknown command"
					packet = self.set_packet(0, msg)
					conn.sendall(packet)
		except Exception as e:
			# print(e)
			logging.debug(e)

	def git_daemon(self):
		# subprocess.run(["git", "daemon", "--base-path=repositories", "--export-all", "--init-timeout=30"])
		subprocess.run(["git", "daemon", "--base-path=repositories", "--export-all", "--reuseaddr"])

	def get_repos(self):
		repos = []
		dir_list = [f.path for f in os.scandir("repositories") if f.is_dir()]
		for i in dir_list:
			repos.append(i.split("/")[1])

		return repos

	def list_peers(self):
		"""
		Sends a request to the server for the
		list of peers in the P2P network.
		"""
		try:
			print("====================")
			with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as udp_socket:
				udp_socket.settimeout(1)
				packet = self.set_packet(2)
				udp_socket.sendto(packet, self.server_udp_addr)
				received = udp_socket.recvfrom(516)
				self.handle_packet(received[0])
				print("==================== \n")
		except Exception as e:
			# print(e)
			logging.debug(e)
			print("Can't connect with the server")

	def list_repos(self, tcp_socket):
		"""
		Sends a request to the server for the 
		list of repositores in a peer.
		"""
		try:
			print("====================")
			tcp_socket.settimeout(1)
			packet = self.set_packet(3)
			tcp_socket.sendall(packet)
			received = tcp_socket.recv(516)
			self.handle_packet(received)
			print("==================== \n")
		except Exception as e:
			logging.debug(e)
			print("Can't connect with the server")
	
	def list_repos_in(self, ip):
		try:
			print("====================")
			with socket.socket(socket.AF_INET, socket.SOCK_DGRAM) as udp_socket:
				udp_socket.settimeout(1)
				packet = self.set_packet(4, ip)
				udp_socket.sendto(packet, self.server_udp_addr)
				received = udp_socket.recvfrom(516)
				self.handle_packet(received[0])
				print("==================== \n")
		except Exception as e:
			# print(e)
			logging.debug(e)
			print("Can't connect with the server")

	def git_request(self, tcp_socket, repo_name):
		try:
			print("====================")
			tcp_socket.settimeout(1)
			packet = self.set_packet(7, repo_name)
			tcp_socket.sendall(packet)
			received = tcp_socket.recv(516)
			self.handle_packet(received)
			print("==================== \n")
		except Exception as e:
			# print(e)
			logging.debug(e)

	def set_packet(self, code, data=None):
		
		"""
		Pack the message with a code so the server
		knows how to handle the request from the
		client.
		0 Message
		1 update repos list
		2 list peers in the network
		3 list repos in the peer
		4 git command
		"""

		if(data == None):
			return struct.pack("!H", code)
		else:
			bdata = pickle.dumps(data)
			packet = struct.pack("!H", code) + bdata
			return packet

	def handle_packet(self, packet):
		"""
		Handle the response packet sent from
		the server.
		0 message
		5 list peers in the network
		6 list repositories
		"""
		code = struct.unpack("!H", packet[0:2])
		# message
		if(code[0] == 0):
			data = pickle.loads(packet[2:])
			print(data)
		# peers
		elif(code[0] == 5):
			data = pickle.loads(packet[2:])
			print("Peers in the network")
			for i in data:
				print(i)
		# repositories
		elif(code[0] == 6):
			data = pickle.loads(packet[2:])
			print("Repositories")
			for i in data:
				print(i)
		else:
			print("Unknown code")

	def connect(self, addr):
		with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as tcp_socket:
			tcp_socket.connect(addr)
			while(True):
				try:
					line = input(addr[0] + " tcp conn" + " > ")
					command = line.split(" ")
					if(command[0] == "list"):
						self.list_repos(tcp_socket)

					elif(command[0] == "git"):
						try:
							if(command[1] == "clone"):
								clone = [command[0], command[1], "git://" + addr[0] + "/" + command[2]]
								p = subprocess.Popen(clone, cwd=client.root_dir)
								p.wait()
								# print(clone)
							elif(command[1] == "init"):
								self.git_request(tcp_socket, command[2])
						except Exception as e:
							print("Wrong git command")
							logging.debug(e)
					
					elif(command[0] == "quit"):	
						break

					else:
						print("Unknown command")

				except Exception as e:
					logging.debug(e)


client = client("192.168.1.78", "192.168.1.67")

print("P2P git client")
while(True):
	try:
		line = input(client.myaddr + " > ")
		command = line.split(" ")
		if(command[0] == "connect"):
			if(command[1] == "server"):
				client.connect(client.server_tcp_addr)
			else:
				client.connect((command[1], int(command[2])))

		elif(command[0] == "peers"):
			client.list_peers()

		elif(command[0] == "list"):
			client.list_repos_in(command[1])

		elif(command[0] == "cd"):
			if(os.path.exists(client.root_dir + command[1])):
				client.working_dir = command[1]
				print("Current working directory: " + client.working_dir)

		elif(command[0] == "git"):
			if(command[1] == "init"):
				p = subprocess.Popen(command, cwd=client.root_dir)
				p.wait()
			elif(command[1] == "commit"):
				try:
					commit = [command[0], command[1], command[2]]
					if(command[2] == "-am" or command[2] == "-m"):
						commit_msg = " ".join(command[3:])
						commit.append(commit_msg)
						p = subprocess.Popen(commit, cwd=client.root_dir + client.working_dir)
						p.wait()
					else:
						print("Wrong commit command")
				except Exception as e:
					logging.debug(e)
					print("Wrong commit command")
			elif(command[1] == "remote"):
				if(client.working_dir == ""):
					print("First select a directory with a git repository in it")
				else:
					remote = [command[0], command[1], command[2], command[3], "git://" + client.server_tcp_addr[0] + "/" + command[4]]
					p = subprocess.Popen(remote, cwd=client.root_dir + client.working_dir)
					p.wait()
					p = subprocess.Popen(["git", "remote", "-v"], cwd=client.root_dir + client.working_dir)
					p.wait()
			else:
				if(client.working_dir == ""):
					print("First select a directory with a git repository in it")
				else:
					p = subprocess.Popen(command, cwd=client.root_dir + client.working_dir)
					p.wait()

		elif(command[0] == "quit"):
			break

		else:
			print("Unknown command")

	except Exception as e:
		logging.debug(e)