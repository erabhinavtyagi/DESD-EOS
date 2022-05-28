cc = gcc

fork_demo:	fork_demo.o 
	$(cc) -o fork_demo fork_demo.o

fork_demo.o:	fork_demo.c
	$(cc) -c -o fork_demo.o fork_demo.c

clean :
	rm -rf *.o fork_demo