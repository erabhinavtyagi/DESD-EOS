cc = gcc

piddemo:	piddemo.o 
	$(cc) -o piddemo piddemo.o

piddemo.o:	piddemo.c
	$(cc) -c -o piddemo.o piddemo.c

clean :
	rm -rf *.o piddemo