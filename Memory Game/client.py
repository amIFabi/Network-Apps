import socket, pickle, threading, time, logging

logging.basicConfig(level=logging.DEBUG, filename="client.log", format='%(asctime)s %(message)s',)

class client:
	
	server_addr = ("127.0.0.1", 65432)
	buffer_size = 1024
	winner = False
	lock = threading.RLock()

	def __init__(self, host="127.0.0.1", port=65432):
		self.server_addr = (host, port)
		with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as tcp_socket:
			tcp_socket.connect(self.server_addr)
			self.playing(tcp_socket)

	def receive_data(self, tcp_socket):
		while(True):
			self.lock.acquire()
			data = tcp_socket.recv(self.buffer_size)
			self.print_msg(data)
			if(pickle.loads(data) == "Game finished"):
				self.winner = True
				break
			elif(pickle.loads(data) == "Your turn..."):
				self.lock.release()
				time.sleep(5)

	def send_data(self, tcp_socket):
		self.lock.acquire()
		points = input("point 1: ")
		points += ":" + input("point 2: ")
		tcp_socket.sendall(pickle.dumps(points))
		self.lock.release()

	def playing(self, tcp_socket):
		send_thread = threading.Thread(target=self.send_data, args=(tcp_socket, ), daemon=True)
		rec_thread = threading.Thread(target=self.receive_data, args=(tcp_socket, ), daemon=True)
		send_thread.start()
		rec_thread.start()
		while(not self.winner):
			logging.debug("Playing...")
		
		logging.debug("Gamed finished")
	
	def print_msg(self, data):
		received_data = pickle.loads(data)
		msg = received_data.split(",")
		for i in msg:
			print(i)

game_client = client()