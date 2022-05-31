cc = gcc

pthreadjoin:	pthreadjoin.o 
	$(cc) -o pthreadjoin pthreadjoin.o -lpthread

pthreadjoin.o:	pthreadjoin.c
	$(cc) -c -o pthreadjoin.o pthreadjoin.c

clean :
	rm -rf *.o pthreadjoin