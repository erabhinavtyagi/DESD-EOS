cc = gcc

semme:	semme.o 
	$(cc) -o semme semme.o -lpthread

semme.o:	semme.c
	$(cc) -c -o semme.o semme.c

clean :
	rm -rf *.o semme