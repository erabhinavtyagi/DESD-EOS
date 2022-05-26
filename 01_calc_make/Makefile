cc= gcc

main:	main.o	add.o	sub.o	mul.o	div.o
	$(cc) -o main main.o add.o sub.o mul.o div.o

main.o:	main.c
	$(cc) -c -o main.o main.c

add.o:	add.c
	$(cc) -c -o add.o add.c

sub.o:	sub.c
	$(cc) -c -o sub.o sub.c

mul.o:	mul.c
	$(cc) -c -o mul.o mul.c

div.o:	div.c
	$(cc) -c -o div.o div.c

clean:	
	rm -rf *.o main
