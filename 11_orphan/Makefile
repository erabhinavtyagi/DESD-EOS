cc = gcc

orphandemo:	orphandemo.o 
	$(cc) -o orphandemo orphandemo.o

orphandemo.o:	orphandemo.c
	$(cc) -c -o orphandemo.o orphandemo.c

clean :
	rm -rf *.o orphandemo