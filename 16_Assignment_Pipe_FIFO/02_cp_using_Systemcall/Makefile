cc = gcc

cp_sys:	cp_syscall.o 
	$(cc) -o cp_sys cp_syscall.o
#	export PATH= $PATH:/home/cdac/Music/workserver/16_Assignment_Pipe_FIFO/02_cp_using_Systemcall

cp_syscall.o:	cp_syscall.c
	$(cc) -c -o cp_syscall.o cp_syscall.c

clean :
	rm -rf *.o cp_sys