import socket, time, threading, pickle, json, logging, struct, os, subprocess

# logging.basicConfig(level=logging.DEBUG, filename="server.log", format='%(asctime)s %(message)s',)
logging.basicConfig(level=logging.DEBUG, format='%(asctime)s %(message)s',)

class server():

	def __init__(self, host="127.0.0.1", udp_port=65000, tcp_port=64000):
		self.udp_addr = (host, udp_port)
		self.tcp_addr = (host, tcp_port)
		print("Listening...")
		udp_thread = threading.Thread(target=self.udp_request, args=(self.udp_addr, ))
		tcp_thread = threading.Thread(target=self.tcp_request, args=(self.tcp_addr, ))
		git_thread = threading.Thread(target=self.git_daemon, daemon=True)
		udp_thread.start()
		tcp_thread.start()
		git_thread.start()

	def udp_request(self, udp_addr):
		with socket.socket(socket.AF_INET,socket.SOCK_DGRAM) as udp_socket:
			udp_socket.bind(udp_addr)
			self.handle_udp_req(udp_socket)

	def tcp_request(self, tcp_addr):
		try:
			with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as tcp_socket:
				tcp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
				tcp_socket.bind(tcp_addr)
				tcp_socket.listen(10)
				while(True):
					conn, addr = tcp_socket.accept()
					thread = threading.Thread(target=self.handle_tcp_req, args=(conn, ))
					thread.start()
		except Exception as e:
			logging.debug(e)

	def handle_tcp_req(self, conn):
		try:
			while(True):
				data = conn.recv(516)
				code = struct.unpack("!H", data[0:2])
				if(code[0] == 3):
					repos = self.get_repos()
					packet = self.set_packet(6, repos)
					conn.sendall(packet)
				elif(code[0] == 7):
					repo = pickle.loads(data[2:])
					command = ["git", "init", repo]
					p = subprocess.Popen(command, cwd="repositiories")
					p.wait()
					command = ["git", "config", "receive.denyCurrentBranch", "ignore"]
					p = subprocess.Popen(command, cwd="repositiories" + repo)
					p.wait()
					packet = self.set_packet(0, "Repository created")
					conn.sendall(packet)
				else:
					msg = "Unknown command"
					packet = self.set_packet(0, msg)
					conn.sendall(packet)
		except Exception as e:
			logging.debug(e)

	def handle_udp_req(self, udp_socket):
		"""
		Main thread to handle requests
		"""
		try:
			while True:
				data, addr = udp_socket.recvfrom(516)
				code = struct.unpack("!H", data[0:2])
				if(code[0] == 1):
					thread = threading.Thread(target=self.update_repositories, args=(data[2:], addr, udp_socket))
					thread.start()
				elif(code[0] == 2):
					thread = threading.Thread(target=self.list_peers, args=(addr, udp_socket))
					thread.start()
				elif(code[0] == 4):
					thread = threading.Thread(target=self.list_repos_in, args=(data[2:], addr, udp_socket))
					thread.start()
				
		except Exception as e:
			logging.debug(e)

	def update_repositories(self, repos, addr, udp_socket):
		"""
		Receives a dictionary from the client, this 
		dictionary contains the names of the local
		repos from that client. Creates a JSON file,
		it's name is the IP of the peer.
		"""
		filePath = addr[0] + ".json"
		dict = pickle.loads(repos)
		with open(filePath, "w") as fp:
			json.dump(dict, fp)
		
		packet = self.set_packet(0, "Repositories from " + addr[0] + " updated")
		udp_socket.sendto(packet, addr)
		logging.debug(addr[0] + " repositories updated")

	def list_peers(self, addr, udp_socket):
		"""
		List the IP of all of the peers on the 
		P2P network.
		"""
		logging.debug(addr[0] + " requested list of peers.")
		peers = []
		for i in os.listdir("."):
			if(i.endswith(".json")):
				peer_addr = i.split(".")
				peers.append(".".join(peer_addr[0:4]))
		
		packet = self.set_packet(5, peers)
		udp_socket.sendto(packet, addr)

	def get_repos(self):
		repos = []
		dir_list = [f.path for f in os.scandir("repositories") if f.is_dir()]
		for i in dir_list:
			repos.append(i.split("/")[1])

		return repos

	def git_daemon(self):
		subprocess.run(["git", "daemon", "--base-path=repositories", "--export-all", "--enable=receive-pack", "--reuseaddr"])

	def list_repos(self, conn):
		"""
		List the repositories in the give IP.
		"""
		repos = self.get_repos()
		packet = self.set_packet(6, repos)
		conn.sendall(packet)

	def list_repos_in(self, data, addr, udp_socket):
		ip = pickle.loads(data)
		logging.debug(addr[0] + " requested list of repositories in " + ip)
		file_name = ip + ".json"
		if(os.path.exists(file_name)):	
			with open(file_name) as json_file:
				dict = json.load(json_file)
				if(len(dict["repos"])):
					packet = self.set_packet(6, dict["repos"])
					udp_socket.sendto(packet, addr)
				else:
					msg = "Peer " + ip + " has no repositories."
					packet = self.set_packet(0, msg)
					udp_socket.sendto(packet, addr)
		else:
			msg = "Error: Peer " + ip + " isn't in the network."
			packet = self.set_packet(0, msg)
			udp_socket.sendto(packet, addr)
	
	def set_packet(self, code, data):
		"""
		Create a bytes object from the data and 
		creates a response packet.
		"""
		bdata = pickle.dumps(data)
		packet = struct.pack("!H", code) + bdata
		return packet


# server = server("192.168.1.78", 65432)
server = server("192.168.1.64")