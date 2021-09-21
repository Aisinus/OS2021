#include "pthread.h"
#include "stdio.h"
#include "stdlib.h"

void procces(int *i){
    printf("Start thread %d\n", *i);
    printf("Stop thread %d\n", *i);
}



int main(){
    int n;
    scanf("%d",&n);
    pthread_t* thread = malloc(n * sizeof(pthread_t));
    int *trans = malloc(n * sizeof(int));
    for(int i = 0; i < n; i++){
        printf("Create thread %d\n",i);
        trans[i]=i;
        pthread_create(thread+i, NULL, (void*(*)(void *))procces, trans+i);
    }
    for(int i=0;i<n;i++){
        pthread_join(thread[i], NULL);
    }
    free(thread);
    free(trans);
    return 0;
}