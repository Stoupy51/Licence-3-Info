
hello_world: hello_world.c
	gcc $< -lpthread -o hello_world.o

compteur_seq: compteur_seq.c
	gcc $< -lpthread -o compteur_seq.o

fib_seq: fib_seq.c
	gcc $< -lpthread -o fib_seq.o

fib_seq_2: fib_seq_2.c
	gcc $< -lpthread -o fib_seq_2.o







clean:
	rm -f *.o

restart: clean hello_world compteur_seq fib_seq fib_seq_2

