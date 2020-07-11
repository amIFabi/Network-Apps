import socket, time, random, logging, numpy as np

logging.basicConfig(level=logging.DEBUG, format='%(asctime)s %(message)s',)

class memory:
	
	players = []
	
	def __init__(self, difficulty=4):
		self.board = np.zeros((difficulty ** 2), dtype=np.uint8)
		self.score = np.zeros((difficulty ** 2), dtype=np.uint8)
		self.pairs = int((difficulty ** 2) / 2)
		self.winner = False
		self.scramble()

	def scramble(self):
		for i in range(0, self.pairs):
			self.board[i] = i + 1
			self.board[i + self.pairs] = i + 1

		for i in range(0, self.pairs):
			x = random.randint(self.pairs, (len(self.board) - 1))
			n = self.board[x]
			self.board[x] = self.board[i]
			self.board[i] = n

	def get_position(self, point):
		x = (int(point[0]) - 1) * 4
		x += (int(point[1]) - 1)
		if(self.score[x] != 0):
			return -1 
		else:
			return x

	def verify_move(self, p1, p2, player):
		x1 = self.get_position(p1)
		x2 = self.get_position(p2)
		if(x1 < 0 or x2 < 0 or x1 == x2):
			logging.debug("Invalid move")
			return "Invalid move"
		else:
			if(self.board[x1] == self.board[x2]):
				self.set_score(x1, x2, player)
				logging.debug("Point")
				return "Point"
			else:
				logging.debug("Try again!")
				return "Try again!"

	def add_player(self, client):
		self.players.append(client)
		player_id = self.players.index(client) + 1
		
		return player_id
	
	def get_player(self, client):
		index = self.players.index(client) + 1

		return index

	def set_score(self, x1, x2, player):
		i = self.get_player(player)
		self.score[x1] = i
		self.score[x2] = i
		self.check_winner()

	def check_winner(self):
		self.winner = (np.count_nonzero(self.score) < len(self.score))