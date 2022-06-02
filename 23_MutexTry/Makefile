cc = gcc

mutexTry:	mutexTry.o 
	$(cc) -o mutexTry mutexTry.o -lpthread

mutexTry.o:	mutexTry.c
	$(cc) -c -o mutexTry.o mutexTry.c

clean :
	rm -rf *.o mutexTry