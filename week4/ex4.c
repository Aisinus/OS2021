#include <stdio.h>
#include <stdlib.h>
int main(){
	printf("> ");
	while(1){
		char command[255];
		char lineEnd;
		scanf("%[^\n]%c", command, &lineEnd);
		printf("> ");
		system(command);
	}
	return 0;
}
