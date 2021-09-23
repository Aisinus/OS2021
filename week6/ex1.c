#include "stdio.h"
#include "stdlib.h"
#include "string.h"
typedef struct proccess{
	int bursttime;
	int arrivaltime;
} process_t;

typedef struct CSVtable{
	process_t *data;
	int size;
} table_csv;


table_csv readCSV(const char *filename){
table_csv newTable;
FILE* stream = fopen(filename,"r");
char line[256];
int size=0;
while(fgets(line,256,stream)){
	size++;
}
printf("size=%d\n",size);
freopen(filename,"r",stream);
newTable.size = size;

for(int i=0;i<size;i++){
	fgets(line,256,stream);
	char * delim = strtok(line,",");
	while(delim!=NULL){
		printf("%s\n",delim);
		delim=strtok(NULL,",");
	}
}


return newTable;
}


int main(){
	char filename[256];
	printf("File address: \n");
	scanf("%[^\n]s",filename);
	table_csv csvTable;
	csvTable = readCSV(filename);
}
