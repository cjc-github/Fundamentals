#include <pthread.h>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
 
#define NUM_THREADS    50
 
void *PrintHello(void *threadid)
{
    long tid;
    tid = (long) threadid;
    printf("thread1 #%ld!\n", tid);
    while(1){
        printf("thread1\n");
        sleep(1);
    }
    pthread_exit(NULL);
}
 
void *PrintHello1(void *threadid)
{
    long tid;
    tid = (long) threadid;
    printf("thread2 #%ld!\n", tid);
    while(1){
        printf("thread2\n");
        sleep(1);
    }
    pthread_exit(NULL);
}
 
int main(int argc, char *argv[])
{
    pthread_t threads[NUM_THREADS];
    int rc,rc1;
    long t;

    printf("Main thread %ld\n", t);
    rc = pthread_create(&threads[t], NULL, PrintHello, (void *) t);
    if (rc)
    {
        printf("ERROR; return code from pthread_create() is %d\n", rc);
        exit(-1);
    }
    rc1 = pthread_create(&threads[t], NULL, PrintHello1, (void *) t);
    if (rc1)
    {
        printf("ERROR; return code from pthread_create() is %d\n", rc1);
        exit(-1);
    }
    /* Last thing that main() should do */
    pthread_exit(NULL);
}
