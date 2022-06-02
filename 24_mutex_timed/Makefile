cc = gcc

mutex_timedlock:	mutex_timedlock.o 
	$(cc) -o mutex_timedlock mutex_timedlock.o -lpthread

mutex_timedlock.o:	mutex_timedlock.c
	$(cc) -c -o mutex_timedlock.o mutex_timedlock.c

clean :
	rm -rf *.o mutex_timedlock