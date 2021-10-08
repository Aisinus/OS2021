#include <stdlib.h>
#include <unistd.h>
#include <string.h>
//this programm increase vm usage while running
int main(){
    for(int i=1;i<=100;i++){
        char *arr=malloc(1024*1024*100);
        memset(arr,'0',1024*1024*100);
        sleep(1);
    }
}