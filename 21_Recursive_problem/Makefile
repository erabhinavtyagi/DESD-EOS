cc = gcc

recursive_prb:	recursive_prb.o 
	$(cc) -o recursive_prb recursive_prb.o -lpthread

recursive_prb.o:	recursive_prb.c
	$(cc) -c -o recursive_prb.o recursive_prb.c

clean :
	rm -rf *.o recursive_prb