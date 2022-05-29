cc = gcc

forklimit:	forklimit.o 
	$(cc) -o forklimit forklimit.o

forklimit.o:	forklimit.c
	$(cc) -c -o forklimit.o forklimit.c

clean :
	rm -rf *.o forklimit