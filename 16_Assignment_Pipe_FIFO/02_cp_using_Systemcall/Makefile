cc = gcc

cp_syscall:	cp_syscall.o 
	$(cc) -o cp_lb cp_syscall.o -lpthread
#	export PATH= $PATH://home/cdac/Music/workserver/16_Assignment_Pipe_FIFO/02_cp_using_Systemcall

cp_syscall.o:	cp_syscall.c
	$(cc) -c -o cp_syscall.o cp_syscall.c

clean :
	rm -rf *.o cp_syscall