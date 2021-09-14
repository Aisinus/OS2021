#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <unistd.h>

int main(){

	for(int i=1;i<=5;i++){
		fork();
		sleep(3);
	}
	return 0;
}

