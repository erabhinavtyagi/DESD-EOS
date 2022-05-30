cc = gcc

threaddemo:	threaddemo.o 
	$(cc) -o threaddemo threaddemo.o -lpthread

threaddemo.o:	threaddemo.c
	$(cc) -c -o threaddemo.o threaddemo.c

clean :
	rm -rf *.o threaddemo