#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct proccess{
	int bursttime;
	int arrivaltime;
	int ct;
	int tat;
	int wt;
	int done;
} process_t;

typedef struct CSVtable{
	process_t *data;
	int size;
} table_csv;


table_csv *readCSV(const char *filename){
	FILE* stream = fopen(filename,"r");
	char line[256];
	int size=0;
		while(fgets(line,256,stream)){
		size++;
		}
	//printf("size=%d\n",size);
	freopen(filename,"r",stream);
	process_t *newDataTable = malloc(size * sizeof(process_t));
		for(int i=0;i<size;i++){
		fscanf(stream,"%d,%d",&newDataTable[i].arrivaltime,&newDataTable[i].bursttime);
		newDataTable[i].ct = 0;
		newDataTable[i].tat = 0;
		newDataTable[i].wt = 0;
		newDataTable[i].done=0;
		}
	fclose(stream);
	table_csv *newTable = malloc(sizeof(table_csv));
	newTable->data=newDataTable;
	newTable->size=size;

	return newTable;
}


void tablePrint(table_csv *table){
	double avgtat = 0;
	double avgwt = 0;
	printf("\n#P	AT	BT	CT	TAT	WT\n");
	for(int i=0;i<table->size;i++){
		printf("P%d	%d	%d	%d	%d	%d\n",i+1,table->data[i].arrivaltime,table->data[i].bursttime, table->data[i].ct, table->data[i].tat, table->data[i].wt);
		avgtat += table->data[i].tat;
		avgwt += table->data[i].wt;
	}
	printf("\n\nAverage Turnaround time: %f \nAverage Waiting time: %f \n", avgtat/table->size, avgwt/table->size);

}



void swap(process_t* a, process_t* b){
	process_t t=*a;
	*a=*b;
	*b=t;
}

int partition(process_t arr[], int low, int high){
	process_t pivot = arr[high];
	int i = (low-1);

	for(int j=low;j<=high-1;j++){
		if(arr[j].arrivaltime<pivot.arrivaltime){
			i++;
			swap(&arr[i], &arr[j]);
		}else if(arr[j].arrivaltime==pivot.arrivaltime){
			//printf("hello %d,%d,%d\n",arr[i].bursttime, pivot.bursttime, arr[j].bursttime);
			if(arr[j].bursttime<pivot.bursttime) swap(&arr[j],&arr[high]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}

void quickSort(process_t arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partition(arr, low, high); 
        quickSort(arr, low, pi - 1); 
        quickSort(arr, pi + 1, high); 
    } 
} 



int main(){
	int sum,i;
	int count=0;
	char filename[256];
	int quantum_time=0;
	printf("File address: ");
	scanf("%[^\n]s\n",filename);
	printf("Quatum time: ");
	scanf("%d",&quantum_time);
	table_csv *csvTable=readCSV(filename);
	quickSort(csvTable->data,0,csvTable->size-1);
	int *each_quantum = malloc(csvTable->size * sizeof(int));
	int step = 0;
	int t = 0;
	int done = 0;

	while(done==0){
		done = 1;
		for(int i=0;i<csvTable->size;i++){
			if(csvTable->data[i].done == 1) continue;
			done = 0;
			if(step==0 && t< csvTable->data[i].arrivaltime){
				t = csvTable->data[i].arrivaltime;
				step=1;
			}
			if(t<csvTable->data[i].arrivaltime){
				continue;
			}
			step=1;

			if(each_quantum[i]+quantum_time>=csvTable->data[i].bursttime){
				
				csvTable->data[i].done=1;
				csvTable->data[i].ct = t + (csvTable->data[i].bursttime-each_quantum[i]);
				csvTable->data[i].wt = csvTable->data[i].ct - (csvTable->data[i].arrivaltime + csvTable->data[i].bursttime);
				csvTable->data[i].tat = csvTable->data[i].bursttime + csvTable->data[i].wt;
				t=csvTable->data[i].ct;
				step=0;
				continue;
			}
			each_quantum[i]=each_quantum[i]+quantum_time;
			t=t+quantum_time;

		}
	}

	tablePrint(csvTable);
	free(each_quantum);
	free(csvTable);
}
