#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include <unistd.h>
void commandExecute(char* command){
	int pid = fork();
	if(pid==0){
		int space = 0;
		for(int i=0;i<strlen(command);i++){
			if(command[i]==' ') space++;
		}
		space++;
		int *commanLenght = malloc(sizeof(int)*space);
		for(int i=0;i<space;i++){
			commanLenght[i]=0;
		}
		int k = 0;
		for(int i=0;i<strlen(command);i++){
			if(command[i]==' '){
				commanLenght[k]++;
				k++;
			}
		}
		char **args=malloc(sizeof(char*)*(space));
		for(int i = 0;i<space;i++){
			args[i]=malloc(sizeof(char)*commanLenght[i]);
		}
		int prev = 0;
		int i;
		k = 0;
		for(i = 0; i<strlen(command);i++){
			if(command[i]==' '){
				strncpy(args[k],command+prev, i-prev);
				k++;
				prev = i+1;
			}
		}
		strncpy(args[k],command+prev,i-prev);
		execvp(args[0],args);

	}
	waitpid(pid,NULL,0);

}



int main(){
	printf(">? ");
	while(1){
		char command[255];
		char lineEnd;
		scanf("%[^\n]%c", command, &lineEnd);
		commandExecute(command);
		printf("> ");
	}
	return 0;
}
