cc = gcc

recursive_solution:	recursive_solution.o 
	$(cc) -o recursive_solution recursive_solution.o -lpthread

recursive_solution.o:	recursive_solution.c
	$(cc) -c -o recursive_solution.o recursive_solution.c

clean :
	rm -rf *.o recursive_solution