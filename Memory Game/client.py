import socket, pickle, threading, time, logging

logging.basicConfig(level=logging.DEBUG, format='%(asctime)s %(message)s',)

class client:
	
	server_addr = ("127.0.0.1", 65432)
	buffer_size = 1024
	winner = False
	your_turn = False
	turn = threading.Condition()

	def __init__(self, host="127.0.0.1", port=65432):
		self.server_addr = (host, port)
		with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as tcp_socket:
			tcp_socket.connect(self.server_addr)
			self.playing(tcp_socket)

	def receive_message(self, tcp_socket):
		# while(not self.winner):
		with self.turn:
			if(self.your_turn):
				self.turn.wait()
			else:
				print("Wait your turn")
				data = tcp_socket.recv(self.buffer_size)
				self.print_msg(data)
				self.turn.notify()

	def make_move(self, tcp_socket):
		# while(not self.winner):
		with self.turn:
			if(self.your_turn):
				print("Make your move")
				points = input("point 1: ")
				points += ":" + input("point 2: ")
				tcp_socket.sendall(pickle.dumps(points))
				self.your_turn = False
				self.turn.notify()
			else:
				self.turn.wait()
	
	def print_msg(self, data):
		received_data = pickle.loads(data)
		msg = received_data.split(",")
		if(msg[0] == "Game finished"):
			self.winner = True
		elif(msg[0] == "Your turn"):
			self.your_turn = True

		for i in msg:
			print(i)

	def play(self, tcp_socket):
		while(not self.winner):
			self.make_move(tcp_socket)
	
	def listen_msg(self, tcp_socket):
		while(not self.winner):
			self.receive_message(tcp_socket)
		
	def playing(self, tcp_socket):
		rec_thread = threading.Thread(target=self.listen_msg, args=(tcp_socket, ), daemon=True)
		send_thread = threading.Thread(target=self.play, args=(tcp_socket, ), daemon=True)
		send_thread.start()
		rec_thread.start()
		while(not self.winner):
			time.sleep(1)
		
		send_thread.join()
		rec_thread.join()

game_client = client()

