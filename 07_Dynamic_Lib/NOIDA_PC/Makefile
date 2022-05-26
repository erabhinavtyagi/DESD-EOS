cc = gcc
myproject:	myproject.o libstatic.so
	$(cc) -o myproject myproject.c -L. -lstatic

myproject.o:	myproject.c
	$(cc) -c -o myproject.o	myproject.c

clean:
	rm -rf *.o myproject