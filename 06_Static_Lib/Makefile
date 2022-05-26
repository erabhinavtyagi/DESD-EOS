cc = gcc

stat_lib_demo:stat_lib_demo.o add.o sub.o
	$(cc) -o stat_lib_demo stat_lib_demo.o add.o sub.o
	ar crv libstatic.a add.o sub.o

stat_lib_demo.o: stat_lib_demo.c 
	$(cc) -c -o stat_lib_demo.o stat_lib_demo.c

add.o: add.c
	$(cc) -c -o add.o add.c

sub.o: sub.c
	$(cc) -c -o sub.o sub.c

clean:
	rm -rf *.o stat_lib_demo


