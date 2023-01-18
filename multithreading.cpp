#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <iostream>
#include <time.h>
using namespace std;
int shared_counter=0;
int N=500+212;
void *start_routine(void *vargp)
{
    int sleepDuration=pthread_self()%10;
    struct timespec tp = {0,sleepDuration};
    for(int j=0;j<N;j++){
    cout <<"I am thread "<<pthread_self()<<" and I'm going to sleep for "<<sleepDuration<<"NS"<<endl;
    nanosleep(&tp, NULL);
    cout <<"I am thread "<<pthread_self()<<" about to increment the Glopal Variable the old value was: "<<shared_counter<<endl;
    shared_counter++;
    cout <<"I am thread "<<pthread_self()<<" done incrementing the Glopal Variable the new value is: "<<shared_counter<<endl;
    }
}

int main(){
    
    pthread_t myThreads[N];
    for(int i=0;i<N;i++)
        pthread_create(&myThreads[i], NULL, start_routine, NULL);
    for(int i=0;i<N;i++)
        pthread_join(myThreads[i],NULL);
}