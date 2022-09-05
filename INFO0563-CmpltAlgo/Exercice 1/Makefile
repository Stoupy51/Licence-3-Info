
main.exe: main.o ListeEntier.o
	gcc -o $@ $^

main.o: main.c ListeEntier.o
	gcc -c $<

ListeEntier.o: ListeEntier.c ListeEntier.h
	gcc -c $<

clean:
	rm -f *.o

delete: clean
	rm -f main.exe

restart: delete main.exe


