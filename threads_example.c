/*
https://www.youtube.com/watch?v=ldJ8WGZVXZk
*/

#include <pthread.h>
#include <stdlib.h>
#include <stdio.h>

void * computation(void * add);

int main(){
    pthread_t thread1;
    pthread_t thread2;
    
    long value1 = 1;
    long value2 = 2;
    
    
    /* Running both task in one without using threads
    computation ( (void *) &value1 );
    computation ( (void *) &value2 );
    */

    pthread_create(&thread1, NULL, computation, (void *)&value1); 
    
    //computation ( (void *) &value1 ); // it waits to finish the first thread, and executes the second one 
    
    pthread_create(&thread2, NULL, computation, (void *)&value2); 
    
    pthread_join(thread1, NULL);
    pthread_join(thread2, NULL);

}


void * computation(void * add){
    long *add_num = (long *) add; 
    long sum = 0;
    
    for(long i=0; i<1000000000; i++){
        sum += * (add_num); 
    }
    
    printf("Add number: %ld \n", *(add_num)); 
    return NULL; 
}