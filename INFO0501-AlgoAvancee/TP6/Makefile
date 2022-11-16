
main.uwu: main.o table_hachage.o liste.o cellule.o noeud.o includes.o
	gcc -o $@ $^

main.o: main.c table_hachage.o liste.o cellule.o noeud.o includes.o
	gcc -c $<

table_hachage.o: table_hachage.c table_hachage.h liste.o cellule.o includes.o
	gcc -c $<

liste.o: liste.c liste.h cellule.o includes.o
	gcc -c $<

cellule.o: cellule.c cellule.h includes.o
	gcc -c $<

noeud.o: noeud.c noeud.h includes.o
	gcc -c $<

includes.o: includes.c includes.h
	gcc -c $<


############
clean:
	rm -f *.o

delete: clean
	rm -f main.uwu

restart: delete main.uwu

