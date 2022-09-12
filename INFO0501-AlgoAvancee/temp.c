
// Ensembles disjoints
composantes-connexes(G)
	Pour chaque sommet V appartenant à G.sommets
		créer-ensemble(V)
	Pour chaque arete (u,v) appartenant à G.aretes
		Si trouver-ensemble(u) != trouver-ensemble(v)
			union(u,v) // unie les ensembles de u et v

meme-composante(u,v)
	return trouver-ensemble(u) == trouver-ensemble(v)

