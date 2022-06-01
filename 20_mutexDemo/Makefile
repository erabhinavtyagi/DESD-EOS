cc = gcc

mutexdemo:	mutexdemo.o 
	$(cc) -o mutexdemo mutexdemo.o -lpthread

mutexdemo.o:	mutexdemo.c
	$(cc) -c -o mutexdemo.o mutexdemo.c

clean :
	rm -rf *.o mutexdemo