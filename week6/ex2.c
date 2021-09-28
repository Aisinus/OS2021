#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct proccess{
	int bursttime;
	int arrivaltime;
	int ct;
	int tat;
	int wt;
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

// Sort by arrivalTime

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
//////////////////////////////////////////////////////////////////////////////////////////////

// Sort by BurstTime
int partitionBurst(process_t arr[], int low, int high){
	process_t pivot = arr[high];
	int i = (low-1);

	for(int j=low;j<=high-1;j++){
		if(arr[j].bursttime<pivot.bursttime){
			i++;
			swap(&arr[i], &arr[j]);
		}
	}
	swap(&arr[i+1],&arr[high]);
	return (i+1);
}

void quickSortBurst(process_t arr[], int low, int high) 
{ 
    if (low < high) 
    { 
        int pi = partitionBurst(arr, low, high); 
        quickSortBurst(arr, low, pi - 1); 
        quickSortBurst(arr, pi + 1, high); 
    } 
} 
/////////////////////////////////////////////



void free_table(table_csv *table){
free(table->size);
free(table);
}


int main(){
	char filename[256];
	printf("File address: \n");
	scanf("%[^\n]s",filename);
	table_csv *csvTable=readCSV(filename);



	quickSort(csvTable->data,0,csvTable->size-1);
	int t = 0;
	for(int i=0;i<csvTable->size;i++){

		if(t == 0){
			t = csvTable->data[i].arrivaltime;
		}
		int wt = t - csvTable->data[i].arrivaltime;
		if(wt<0){
		 	wt=0;
		}
		csvTable->data[i].ct = csvTable->data[i].arrivaltime + wt + csvTable->data[i].bursttime;
		csvTable->data[i].tat = wt + csvTable->data[i].bursttime;
		csvTable->data[i].wt = wt;
		t = csvTable->data[i].ct;

		int next_size=0;
		for(int j=i+1;j<csvTable->size;j++){
			
			if(csvTable->data[i].ct>=csvTable->data[j].arrivaltime){
				next_size++;
			}
		}
		quickSortBurst(csvTable->data,i+1,next_size);

	}


	tablePrint(csvTable);
	
	free(csvTable);
}
