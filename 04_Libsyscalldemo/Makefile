cc = gcc

libsyscalldemo:	libsyscalldemo.o 
	$(cc) -o libsyscalldemo libsyscalldemo.o

libsyscalldemo.o:	libsyscalldemo.c
	$(cc) -c -o libsyscalldemo.o libsyscalldemo.c

clean :
	rm -rf *.o libsyscalldemo