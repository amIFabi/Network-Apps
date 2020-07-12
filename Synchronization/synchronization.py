import logging, threading, time

logging.basicConfig(level=logging.DEBUG, format='%(asctime)s %(message)s')

class workshop:

	def __init__(self, start=0):
		self.max_sleeves = threading.Condition()
		self.min_sleeves = threading.Condition()
		self.min_bodies = threading.Condition()
		self.max_bodies = threading.Condition()
		self.sleeves = 0
		self.bodies = 0
		self.shirts = 0

	def add_sleeve(self):
		with self.max_sleeves:
			if(self.sleeves > 9):
				logging.debug("There's no space for sleeves")
				self.max_sleeves.wait()
			else:
				self.sleeves += 1
				logging.debug("Sleeve created, sleeves=%s", self.sleeves)
		
		with self.min_sleeves:
			if(self.sleeves > 1):
				logging.debug("There's sleeves available")
				self.min_sleeves.notify()

	def remove_sleeves(self):
		time.sleep(5)
		with self.min_sleeves:
			while(not self.sleeves > 1):
				logging.debug("Waiting for sleeves...")
				self.min_sleeves.wait()
			
			self.sleeves -= 2
			logging.debug("Sleeves removed, sleeves=%s", self.sleeves)
		
		with self.max_sleeves:
			logging.debug("There's space for sleeves")
			self.max_sleeves.notify()

	def add_body(self):
		with self.max_bodies:
			if(self.bodies > 9):
				logging.debug("There's no space for bodies")
				self.max_bodies.wait()
			else:
				self.bodies += 1
				logging.debug("Body created, bodies=%s", self.bodies)
		
		with self.min_bodies:
			if(self.bodies > 0):
				logging.debug("There's bodies available")
				self.min_bodies.notify()

	def remove_bodie(self):
		with self.min_bodies:
			while(not self.bodies > 0):
				logging.debug("Waiting for bodies...")
				self.min_bodies.wait()

			self.bodies -= 1
			logging.debug("Body removed, bodies=%s", self.bodies)

		with self.max_bodies:
			logging.debug("There's space for bodies")
			self.max_bodies.notify()

	def create_sleeve(self):
		while(self.shirts < 10):
			self.add_sleeve()
			time.sleep(5)

	def create_body(self):
		while(self.shirts < 10):
			self.add_body()
			time.sleep(5)

	def create_shirt(self):
		while(self.shirts < 10):
			self.remove_bodie()
			self.remove_sleeves()
			self.shirts += 1
			time.sleep(1)
			logging.debug("Shirt created, shirts=%s", self.shirts)

ws = workshop()

worker1 = threading.Thread(target=ws.create_sleeve, daemon=True)
worker2 = threading.Thread(target=ws.create_body, daemon=True)

worker1.start()
worker2.start()
ws.create_shirt()
logging.debug("Shirts finished!")
worker1.join()
worker2.join()