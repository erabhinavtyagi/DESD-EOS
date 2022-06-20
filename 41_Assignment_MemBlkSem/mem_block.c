// Assignment : Counting Semaphore
// Memory Block Manager - Using the counting semaphore to manage the memory blocks.
// Provide functionality - getblock() & releaseblock() for 3 Memory block of 20bytes.
// functions will return pointer to the memory location. 


#include<pthread.h>
#include<stdio.h>
#include<semaphore.h>
#include<unistd.h> 

sem_t s;

typedef enum {
              Byte = 1,     //unsigned char
              Int32 = 2,    //int
              Float32 = 3,  //float
              Float64 = 4   //double 
}DataType;

size_t mem_size(DataType type)
{
    switch (type) {
    case Byte: return sizeof(unsigned char);
    case Int32: return sizeof(unsigned int); // Shouldn't this be uint32_t?
    case Float32: return sizeof(float);
    case Float64: return sizeof(double);
    }
}

void *allocate_mem(DataType type, size_t x, size_t y) {
    size_t pixel_count = x * y; // overflow checking omitted
    size_t byte_count = pixel_count * pixel_size(type); // overflow checking omitted;
    return malloc(byte_count);
}

void *getblock(void *data)
{
    int n = *(int *)data;
        
    sem_wait(&s);
    printf("Thread[%d] acquired the resource.\n", n);
    sleep(1);
    sem_post(&s);
    printf("Thread[%d] finished\n", n);
}

void *releaseblock(void *data)
{


}

int main()
{
    sem_init(&s, 0, 3);         // for 3Memory Block
    int num;
    printf("Enter the number of Threads: \n");
    scanf("%d",&num);

    pthread_t thread[num];

    for(int i=1;i<=num;i++)
    {
        pthread_create(&thread[i],NULL,getblock,&i);
    }
    
    for(int i=1;i<=num;i++)
    {
        pthread_join(thread[i],NULL);
    }
return 0;
}