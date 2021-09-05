#include <stdio.h>

void bubble_sort(int* arr, int size){
	int t;
	for (int c = 0 ; c < size - 1; c++) {
    for (int d = 0 ; d < size - c - 1; d++) {
      if (arr[d] > arr[d+1]) {
        t  		  = arr[d];
        arr[d]   = arr[d+1];
        arr[d+1] = t;
      }
    }
  }
}



int main(){
	int n;
	printf("print size of array ");
	scanf("%d",&n);
	int arr[n];
	printf("print array\n");
	for(int i=0;i<n;i++){
		scanf("%d",&arr[i]);
	}
	bubble_sort(arr,n);
	printf("Sorrted array: ");
	for(int i=0;i<n;i++){
		printf("%d ", arr[i]);
	}
	return 0;
}
