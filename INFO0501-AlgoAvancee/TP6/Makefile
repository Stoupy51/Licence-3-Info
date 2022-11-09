
main.exe: main.o table_hachage.o liste.o cellule.o
	gcc -o $@ $^

main.o: main.c table_hachage.o liste.o cellule.o
	gcc -c $<

table_hachage.o: table_hachage.c table_hachage.h liste.o cellule.o
	gcc -c $<

liste.o: liste.c liste.h cellule.o
	gcc -c $<

cellule.o: cellule.c cellule.h
	gcc -c $<


############
clean:
	rm -f *.o

delete: clean
	rm -f main.exe

restart: delete main.exe


