
main: st_benchmark.o
	gcc $< -o main.exe

st_benchmark: st_benchmark.c st_benchmark.h
	gcc -c $< -o st_benchmark.o

#####################################
#####################################
#####################################

clean:
	rm -f *.exe
	rm -f *.o

restart: clean st_benchmark main

