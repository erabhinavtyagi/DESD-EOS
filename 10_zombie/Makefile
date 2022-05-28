cc = gcc

zombiedemo:	zombiedemo.o 
	$(cc) -o zombiedemo zombiedemo.o

zombiedemo.o:	zombiedemo.c
	$(cc) -c -o zombiedemo.o zombiedemo.c

clean :
	rm -rf *.o zombiedemo