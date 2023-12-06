/*
g++ pthread.cpp -o pthread -pthread

Usage:
./pthread

*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>

void* main_thread(void* arg) {
    while(1){
        printf("Secondary thread\n");
        sleep(1);
    }
    return NULL;
}

int main() {
    pthread_t pd;
    pthread_attr_t pAttr;

    pthread_attr_init(&pAttr);
    pthread_attr_setdetachstate(&pAttr, PTHREAD_CREATE_DETACHED);

    if (pthread_create(&pd, &pAttr, main_thread, NULL) != 0) {
        printf("Failed creating main_thread thread\n");
        return 1;
    }

    while(1){
        printf("Main Thread\n");
        sleep(1);
    }
        
    pthread_attr_destroy(&pAttr);
    pthread_join(pd, NULL);
    pthread_exit(NULL);
}
