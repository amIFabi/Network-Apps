import socket, time, threading, pickle, logging, math
import numpy as np
from game import memory

logging.basicConfig(level=logging.DEBUG, format='%(asctime)s %(message)s',)

class server:

	buffer_size = 1024
	turn = threading.Condition()
	player = 1
	move_board = ""

	def __init__(self, host="127.0.0.1", port=65432):
		self.server_addr = (host, port)
		self.clients = []
		self.threads = []
		# print("Choose difficulty: ")
		# print("1) 4 x 4: ")
		# print("2) 6 x 6: ")
		# diff = int(input())
		# self.game = memory(diff)
		self.game = memory()

		# print("How many players: ")
		# self.player_slots = int(input())
		self.player_slots = 2
		self.barrier = threading.Barrier(self.player_slots)
		
		with socket.socket(socket.AF_INET, socket.SOCK_STREAM) as tcp_socket:
			tcp_socket.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
			tcp_socket.bind(self.server_addr)
			tcp_socket.listen(self.player_slots)
			logging.debug("Waiting for " + str(self.player_slots) + " players")

			self.connection_handler(tcp_socket)
		
	def connection_handler(self, tcp_socket):
		try:
			while self.player_slots:
				client_conn, client_addr = tcp_socket.accept()
				self.player_slots -= 1
				if(self.player_slots):
					logging.debug("Waiting for " + str(self.player_slots))

				logging.debug("Connection established with: " + str(client_addr))
				self.clients.append(client_conn)
				self.game.add_player(client_addr[1])
				
				msg = str(len(self.clients)) + " players connected,Waiting for " + str(self.player_slots) + ", "
				data = pickle.dumps(msg)
				client_conn.sendall(data)

				thread_read = threading.Thread(target=self.playing, args=(client_conn, client_addr))
				self.threads.append(thread_read)
				thread_read.start()

		except Exception as e:
			print(e)

	def connection_management(self):
		for connection in self.clients:
			if(connection.fileno() == -1):
				self.clients.remove(connection)

	def move(self, conn, addr):
		with self.turn:
			if(self.game.get_player(addr[1]) == self.player):
				conn.sendall(pickle.dumps("Your turn"))
				data = conn.recv(self.buffer_size)
				points = pickle.loads(data)
				point1, point2 = get_points(points)
				
				# data = make_move(self.game, point1, point2, addr[1])
				self.move_board = make_move(self.game, point1, point2, addr[1])
				# conn.sendall(data)

				self.player %= len(self.clients)
				self.player += 1
				logging.debug("Player %s turn", self.player)
				self.turn.notify()
				# time.sleep(5)
			else:
				self.turn.wait()

	def playing(self, conn, addr):
		try:
			self.barrier.wait()
			while(not self.game.winner):
				self.move(conn, addr)
				for i in self.clients:
					i.sendall(pickle.dumps(self.move_board))
			
			conn.sendall(pickle.dumps("Game finished"))

		except Exception as e:
			print(e)
		finally:
			conn.close()

def get_points(p):
	points = p.split(":")
	point1 = points[0].split(",")
	point2 = points[1].split(",")

	return point1, point2

def make_move(game, point1, point2, player):
	msg = game.verify_move(point1, point2, player)

	if(msg == "Invalid move"):
		msg += ", "
		# data = pickle.dumps(msg)
	else:
		board = game.str_board_move(point1, point2)
		msg += "," + board
		score = game.count_scores()
		msg += score
		# data = pickle.dumps(msg)

	return msg

serv = server()
