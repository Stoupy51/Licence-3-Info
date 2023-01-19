
exo1: exo1.c
	gcc $< -lpthread -o exo1.o

mat_vec: mat_vec.c
	gcc $< -lpthread -lncurses -o mat_vec.o

#####################################
#####################################
#####################################

clean:
	rm -f *.o

restart: clean exo1 mat_vec

