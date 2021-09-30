#include "stdio.h"
#include "stdlib.h"
#include "string.h"

void *own_realloc(void *ptr, size_t size){
	if(size == 0){ 
		free(ptr);
		return;
	}
	void *new_ptr = malloc(size);
	if(ptr!=NULL){
	memcpy(new_ptr,ptr,size);
	free(ptr);
	}
	return new_ptr;
}

int main(){
	int n1=0;
	scanf("%d",&n1);

	int* a1 = malloc(n1*sizeof(int));
	int i;
	for(i=0; i<n1; i++){
		a1[i]=100;
		printf("%d ",a1[i]);
	}

	
	printf("\nEnter new array size: ");
	int n2=0;
	scanf("%d",&n2);

	
	a1 = own_realloc(NULL,n2*sizeof(int));

	
	if(n2>n1){

for(i=n1; i<n2; i++){
		a1[i]=0;
		
	}
}
	for(i=0; i<n2;i++){
		
	printf("%d ",a1[i]);
	}
	printf("\n");
	free(a1);
	return 0;
}