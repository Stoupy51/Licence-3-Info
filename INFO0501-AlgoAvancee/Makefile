
main.uwu: main.o graphe.o liste.o queue.o tas.o pile.o cellule.o sommet.o arete.o file_priorites_min.o
	gcc -o $@ $^

main.o: main.c graphe.o liste.o queue.o tas.o pile.o cellule.o sommet.o arete.o file_priorites_min.o
	gcc -c $<

graphe.o: graphe.c graphe.h liste.o queue.o tas.o pile.o cellule.o sommet.o arete.o file_priorites_min.o
	gcc -c $<

liste.o: liste.c liste.h cellule.o
	gcc -c $<

queue.o: queue.c queue.h sommet.o
	gcc -c $<

tas.o: tas.c tas.h arete.o
	gcc -c $<

pile.o: pile.c pile.h
	gcc -c $<

cellule.o: cellule.c cellule.h
	gcc -c $<

sommet.o: sommet.c sommet.h
	gcc -c $<

arete.o: arete.c arete.h
	gcc -c $<

file_priorites_min.o: file_priorites_min.c file_priorites_min.h
	gcc -c $<

clean:
	rm -f *.o

delete: clean
	rm -f main.uwu

restart: delete main.uwu


