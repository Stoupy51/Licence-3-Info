
import timeit
import tp_primes
from random import randint
from arithmetiqueDansZ import *
from Binaire603 import Binaire603

from CodeurCA import CodeurCA

class ChiffreurRSA(CodeurCA):
	""""""
	def __init__(self, e = 7, d = 103, n = 143):
		if isinstance(e, ChiffreurRSA):
			self.e = e.e
			self.d = e.d
			self.n = e.n
		else:
			self.e = ElementDeZnZ(e, n)
			self.d = ElementDeZnZ(d, n)
			self.n = n
	
	def generateKeys(maxPrime = 100):
		assert maxPrime < tp_primes.pLen, "maxPrime trop grand"
		assert maxPrime >= 100, "maxPrime trop petit"
		p = tp_primes.p[randint(0, maxPrime)]
		q = p
		while (p == q):
			q = tp_primes.p[randint(0, maxPrime)]
		n = p * q
		phi = (p - 1) * (q - 1)
		e = p
		d = n
		while (e > phi or d > phi):
			while (e == p or e == q or e > phi or sontPremiers(e, phi) != 1):
				e = tp_primes.p[randint(0, maxPrime)]
			d = ElementDeZnZ(e, phi).inverse().rep
		#print(f"p = {p}, q = {q}, n = {n}, phi = {phi}, e = {e}, d = {d}")
		return (e, d, n)

	def __str__(self):
		return f"ChiffreurRSA avec e = {self.e}, d = {self.d} et n = {self.n}"
	def __repr__(self):
		return f"ChiffreurRSA({self.e=}, {self.d=}, {self.n=})"

	def binCode(self, monBinD):
		""" Chiffre un message binaire en utilisant la clé publique
		#>>> ChiffreurRSA().binCode(Binaire603("Bonjour"))
		Binaire603([ 0x0a, 0x0a, 0x0a, 0x0a, 0x0a])
		"""
		if (isinstance(monBinD, str)):
			monBinD = Binaire603(monBinD)
		return [ (b ** self.e).rep for b in monBinD ]
	
	def __call__(self, monBinD):
		return self.binCode(monBinD)

	def binDecode(self, monBinC):
		if (isinstance(monBinC, str)):
			monBinC = Binaire603(monBinC)
		return [ (c ** self.d).rep for c in monBinC ]


if __name__ == "__main__":
	import doctest
	doctest.testmod()
	print("Très grosses clés :", ChiffreurRSA.generateKeys(tp_primes.pLen-1))
	print("Très petites clés :", ChiffreurRSA.generateKeys())

	# Test de chiffrement et déchiffrement
	f = ChiffreurRSA()
	texte = "Bonjour"
	list1 = []
	for i in texte:
		list1.append(ord(i))
	c = f(texte)
	d = f.binDecode(c)
	print(f"\n{f}")
	print("Texte :", texte)
	print("Texte binaire :", list1)
	print("Chiffré binaire :", c)
	print("Déchiffré binaire :", d)
	print("Déchiffré :", Binaire603(d).toString())
 
	print("\nTest de déchiffrement avec 100 clés aléatoires : ")
	for i in range(100):
		ce, cd, cn = ChiffreurRSA.generateKeys(100)
		f = ChiffreurRSA(ce, cd, cn)
		c = f(texte)
		d = f.binDecode(c)
		if (i % 10 == 0):
			print(f"Test {i+1}")
		if (list1 != d):
			print(f"Erreur de déchiffrement avec la clé {ce, cd, cn}")
			raise Exception("Erreur de déchiffrement")
	print("100 tests de déchiffrement réussis, toutes les clés sont valides !")

