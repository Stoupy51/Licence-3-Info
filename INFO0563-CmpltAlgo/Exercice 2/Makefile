
main.exe: main.o Monome.o
	gcc -o $@ $^

main.o: main.c Monome.o
	gcc -c $<

Monome.o: Monome.c Monome.h
	gcc -c $<

clean:
	rm -f *.o

delete: clean
	rm -f main.exe

restart: delete main.exe


