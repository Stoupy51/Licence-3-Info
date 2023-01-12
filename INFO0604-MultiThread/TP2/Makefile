
exo1: exo1.c
	gcc $< -lpthread -o exo1.o

sousPref: sousPref.c queue.o
	gcc $< -lpthread queue.o -o sousPref.o

queue.o: queue.c queue.h
	gcc -c $<

#####################################
#####################################
#####################################

clean:
	rm -f *.o

restart: clean exo1 sousPref

