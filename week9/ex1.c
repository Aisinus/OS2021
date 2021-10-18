#include "stdint.h"
#include "stdlib.h"
#include "unistd.h"
#include "math.h"
#include "stdio.h"


typedef struct{
    int id;
    uint16_t age;
} page_t;



void printStep(FILE* file, page_t page[], int size){
    for(int i=0;i<size;i++){
        fprintf(file,"i=%d id = %d %d \n",i,page[i].id, page[i].age);
    }
    fprintf(file,"\n");
}


int minAge(page_t page[], int size){
    uint16_t min = pow(2,16);
    int freespace = -1;
    int index;
    for(int i=0;i<size;i++){
        if(page[i].age<=min && page[i].id !=-1){
            index = i;
            min = page[i].age;
        }

        if(page[i].age<=min && page[i].id ==-1){
            freespace = i;
            min = page[i].age;
        }

    }
    if(freespace!=-1) return freespace;
    return index;
}


void read_page(FILE* stream,page_t page[], int size){
   FILE* write = fopen("out.txt", "w");
    int pageID;
    double hit = 0;
    double miss = 0;
    fscanf(stream,"%d", &pageID);
    while(!feof(stream)){
        int hitMoment = 0;
        for(int i=0;i<size;i++){
            page[i].age = page[i].age>>1;

            if(pageID==page[i].id){
                hitMoment++;
                page[i].age = page[i].age | (uint16_t)pow(2,15);
 
            }
        }
        if(hitMoment != 1){
            miss++;
            int swap = minAge(page, size);
            page[swap].id = pageID;
            page[swap].age = pow(2,15);
        }else{
            hit++;
        }
        fprintf(write,"input %d\n", pageID);
        printStep(write, page, size);  
        
        fscanf(stream,"%d", &pageID);
    }
    fprintf(write,"\nhit:%f, miss:%f, ratio:%f\n", hit,miss,hit/miss);
    fclose(write);
    printf("hit:%f, miss:%f, ratio:%f\n", hit,miss,hit/miss);
}



int main(){
    int size;
    printf("MMU size: \n");
    scanf("%d",&size);
    page_t *page = malloc(size * sizeof(page_t));
    for(int i = 0; i<size;i++){
    page[i].id = -1;
    }
    FILE* stream = fopen("input.txt", "r");
    read_page(stream,page,size);
    fclose(stream);
}
