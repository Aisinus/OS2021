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

	printf("\n#P  AT  BT  CT  TAT  WT\n");
	for(int i=0;i<table->size;i++){
		printf("P%d  %d   %d   %d   %d    %d\n",i+1,table->data[i].arrivaltime,table->data[i].bursttime, table->data[i].ct, table->data[i].tat, table->data[i].wt);
	}
	
	printf("\n\nAverage Turnaround: \nAverage Waiting: \n");



	// for(int i=0;i<table->size;i++){
	// 	printf("%d,%d,%d,%d,%d\n",table->data[i].arrivaltime,table->data[i].bursttime, table->data[i].ct, table->data[i].tat, table->data[i].wt);
	// }
	
}

void free_table(table_csv *table){
free(table->size);
free(table);
}


int main(){
	char filename[256];
	printf("File address: \n");
	scanf("%[^\n]s",filename);
	table_csv *csvTable=readCSV(filename);
	tablePrint(csvTable);
	free(csvTable);
}
