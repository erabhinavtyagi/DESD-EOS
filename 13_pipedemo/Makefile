cc = gcc

pipedemo:	pipedemo.o 
	$(cc) -o pipedemo pipedemo.o

pipedemo.o:	pipedemo.c
	$(cc) -c -o pipedemo.o pipedemo.c

clean :
	rm -rf *.o pipedemo