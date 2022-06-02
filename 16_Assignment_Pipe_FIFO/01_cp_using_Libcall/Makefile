cc = gcc

cp_lb:	cp_lbcall.o 
	$(cc) -o cp_lb cp_lbcall.o 
#	export PATH= $PATH:/home/cdac/Music/workserver/16_Assignment_Pipe_FIFO/01_cp_using_Libcall

cp_lbcall.o:	cp_lbcall.c
	$(cc) -c -o cp_lbcall.o cp_lbcall.c

clean :
	rm -rf *.o cp_lb
