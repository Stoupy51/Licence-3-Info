
if __name__ == "__main__":
	import doctest
	doctest.testmod()
	print("Tests des fonctions du TP1 validé")


# Exercice 1
def secondDiviseur(a):
	"""Renvoie le premier diviseur positif de a supérieur à 1
	>>> secondDiviseur(15845465)
	5
	"""
	# Cas a = 1 ou 2
	if a < 3:
		return a
	# On teste de 3 jusqu'à la racine carré de a en pas de 2
	for b in range(3, sqrt(a) + 1, 2):
		if a % b == 0:
			return b
	return a

def eDiviseurs(a):
	"""renvoie l'ensemble des diviseurs positifs de a
	>>> eDiviseurs(60)
	{1, 2, 3, 4, 5, 6, 10, 12, 15, 20, 60, 30}
	>>> eDiviseurs(1) == set({1}) and eDiviseurs(13) == set({1, 13})
	True
	"""
	# Definition de l'ensemble
	r = set({1, a})
	# On rempli l'ensemble
	for b in range(1, sqrt(a)+1):
		if a % b == 0:
			r += b
			r += a // b
	return r


# Exercice 2
def logDiscret(self, b):
	"""Renvoie x tel que self.a ** x == b(self.n)
	n doit être premier pour garantir l'existence
	>>> elmnZnZ(2, 13).logDiscret(8)
	3
	>>> elmtZnZ(2, 13).logDiscret(3)
	4
	"""
	return 0



class ElmtZnZ(object):
	def __init__(self, val, n = 256):
		"""
		>>> ElmtZnZ(-1, 10)
		ElmtZnZ(9, 10)
		>>> ElmtZnZ(ElmtZnZ(9, 10))
		ElmtZnZ(9, 10)
		"""
		if isinstance(val, ElmtZnZ):
			self.rep = val.rep
			self.n = val.n
		else:
			self.rep = val % n
			self.n = n
	
	def __str__(self):
		return self.rep
	
	def __repr__(self):
		return f"ElmtZnZ({self.rep}, {self.n})"

	def __eq__(self, other):
		"""Compare deux nombrez
		>>> ElmtZnZ(9, 10) == ElmtZnZ(9, 20)
		True
		"""
		if isinstance(other, ElmtZnZ):
			return (self.rep - other.rep) % self.n == 0
		else:
			return (self.rep - other) % self.n == 0
	
	def __add__(self, other):
		"""
		>>> ElmtZnZ(2, 10) + ElmtZnZ(3, 10)
		ElmtZnZ
		"""
		if isinstance(other, ElmtZnZ):		
			return ElmtZnZ(self.rep + other.rep, self.n)
		else:
			return ElmtZnZ(self.rep + other, self.n)

	def __radd__(self, other):
		"""
		>>> 2 + ElmtZnZ(3, 10)
		ElmtZnZ(5, 10)
		"""
		return self.__add__(other, self)

	def __mul__(self, other):
		if isinstance(other, ElmtZnZ):
			return ElmtZnZ(self.rep * other.rep, self.n)
		else:
			return ElmtZnZ(self.rep * other, self.n)
	
	def __rmul__(self, other):
		return self.__mul__(other, self)
	
	def __floordiv__(self, other):
		return 0




class ChiffreurParDecalage(object):
	def __init__(self, decal = 5):
		if isinstance(decal, ChiffreurParDecalage):
			self.decal = decal.decal
		else:
			self.decal = decal

	def chiffrer(self, m, k):
		l = []
		for i in m:
			l.append(i+k)
		return l




