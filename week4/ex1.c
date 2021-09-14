#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){
	int n = 0; //variable n
	int v = fork(); //create new procces with id 0
	if(v==0){
		sleep(0.5); //to fix error with buffer
		printf("Hello from child %d\n", v);
	}else{
		printf("Hello from parrent, parrent id %d and child id %d\n", getpid(), v);
	}
	return 0;
}