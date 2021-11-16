#include "stdint.h"
#include "stdlib.h"
#include "unistd.h"
#include "math.h"
#include "stdio.h"
#include "string.h"

typedef struct Data{
    int* A;
    int* E;
    int resource;
    int process;
    int** request;
    int** current;
    
} data;

void remove_space(char *line){
    char *back = line;
    do{
        if(*back!=' ') *line++=*back;
    }while(*back++!='\0');
}




data *readFile(const char *filename){
    FILE *stream = fopen(filename,"r");
    data *newData = malloc(sizeof(data));
    char line[256];
    int resource = 0;
    int procces = 0;
    while(fgets(line,256,stream)){
        if(strlen(line)==1) continue;
        resource = strlen(line)/2;
        procces++;
    }
    procces=(procces-2)/2;
    newData->resource = resource;
    newData->process = procces;
    newData->A = malloc(resource*sizeof(int));
    newData->E = malloc(resource*sizeof(int));
    newData->request = malloc(procces*sizeof(int*));
    newData->current = malloc(procces*sizeof(int*));
    for(int i=0;i<procces;i++){
        newData->request[i] = malloc(resource*sizeof(int));
        newData->current[i] = malloc(resource*sizeof(int));
    }
    fclose(stream);
    int space = 0;
    stream = fopen(filename,"r");
    while(fgets(line,256,stream)){
        if(strlen(line)==1) continue;
        remove_space(line);
        if(space==0){
            for(int i=0;i<resource;i++){
                newData->E[i] = line[i]-'0';
            }
        }else if(space==1){
            for(int i=0;i<resource;i++){
                newData->A[i] = line[i]-'0';
            }
        }else if(space==2){
            for(int k=0;k<procces;k++){
                for(int i=0;i<resource;i++){
                newData->current[k][i] = line[i]-'0';
                }
            fgets(line,256,stream);
            remove_space(line);
            }
        }else if(space == 3){
            for(int k=0;k<procces;k++){
                for(int i=0;i<resource;i++){
                newData->request[k][i] = line[i]-'0';
                }
            fgets(line,256,stream);
            remove_space(line);
            }
        }
        space++;
    }
    fclose(stream);
    return newData;
}



void printTable(data *table){
    printf("E=");
    for(int i=0;i<table->resource;i++){
        printf("%d, ",table->E[i]);
    }
    printf("\nA=");
    for(int i=0;i<table->resource;i++){
        printf("%d, ",table->A[i]);
    }
    printf("\n\n");
    for(int i=0;i<table->process;i++){
        for(int k=0;k<table->resource;k++){
            printf("%d ",table->current[i][k]);
        }
        printf("\n");
    }
    printf("\n");
    for(int i=0;i<table->process;i++){
    for(int k=0;k<table->resource;k++){
        printf("%d ",table->request[i][k]);
    }
        printf("\n");
    }
}




int main(){
    data *datatable = readFile("input_ok.txt");
   // printTable(datatable);
    int* finish = malloc(datatable->process * sizeof(int));
    for(int i=0;i<datatable->process;i++){
        finish[i]=0;
    }
    for(int i=0;i<datatable->process;i++){
        int check = 1;
        for(int k=0;k<datatable->resource;++k){
            if(datatable->request[i][k]!=0){
                check = 0;
            }
        }
        if(check == 1){
            finish[i] = 1;
            for(int k=0;k<datatable->resource;++k){
                datatable->A[k] = datatable->A[k]+datatable->current[i][k];
            }
        }
    }

    int again;
    while(1){
        again=0;
        for(int i=0;i<datatable->process;++i){
            int check = 1;
            for(int k=0;k<datatable->resource;++k){
                if(datatable->A[k]<datatable->request[i][k]) check = 0;
            }
            if(finish[i]==0 && check==1){
                finish[i]=1;
                again=1;
            for(int k=0;k<datatable->resource;++k){
                datatable->A[k] = datatable->A[k]+datatable->current[i][k];
            }
            }
        }
        if(again==0) break;
    }
    
    int check = 1;
    for(int i=0;i<datatable->process;++i){
        if(finish[i]==0){
            printf("Process %d is deadlocked",i);
            check=0;
        }
    }
    if(check==1) printf("No deadlocked process");
    free(datatable);
}