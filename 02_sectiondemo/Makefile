cc = gcc

sectiondemo:	sectiondemo.o 
	$(cc) -o sectiondemo sectiondemo.o

sectiondemo.o:	sectiondemo.c
	$(cc) -c -o sectiondemo.o sectiondemo.c

clean :
	rm -rf *.o sectiondemo