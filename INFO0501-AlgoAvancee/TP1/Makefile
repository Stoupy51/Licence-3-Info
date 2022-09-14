
main.exe: main.o liste.o cellule.o
	gcc -o $@ $^

main.o: main.c liste.o cellule.o
	gcc -c $<

liste.o: liste.c liste.h cellule.o
	gcc -c $<

cellule.o: cellule.c cellule.h
	gcc -c $<

clean:
	rm -f *.o

delete: clean
	rm -f main.exe

restart: delete main.exe


