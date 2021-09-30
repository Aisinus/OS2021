#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void arrayfill(int arr[],int size){
	for(int i = 0; i<size;i++){
		arr[i]=i;
	}
}

void arrayprint(int arr[],int size){
	for(int i=0;i<size;i++){
		printf("%d\n",arr[i]);
	}
}


int main(){
	int n;
	printf("input size \n");
	scanf("%d",&n);
	int *arr=malloc(n*sizeof(int));
	arrayfill(arr,n);
	arrayprint(arr,n);
	free(*arr);

	return 0;
}