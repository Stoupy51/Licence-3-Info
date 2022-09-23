
main.exe: main.o Abr.o
	gcc -o $@ $^

main.o: main.c Abr.o
	gcc -c $<

Abr.o: Abr.c Abr.h
	gcc -c $<

clean:
	rm -f *.o

delete: clean
	rm -f main.exe

restart: delete main.exe


