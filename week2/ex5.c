#include <stdio.h>
#include <stdlib.h>

void firstFigure(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=i;j++){
            printf("*");
        }
        printf("\n");
    }
}


void secondFigure(int n){
    int mid = n/2+1;
    for(int i=1;i<=n;i++){
        if(i<=mid){
            for(int j=1;j<=i;j++){
                printf("*");
            }
        }else if(i>mid){
            for(int j=0;j<=n - i;j++){
                printf("*");
            }
        }
        printf("\n");
    }
}

void thirdFigure(int n){
    for(int i=1;i<=n;i++){
        for(int j=1;j<=n;j++){
            printf("*");
        }
        printf("\n");
    }
}



int main(int argc, char* argv[])
{
   int n=atoi(argv[1]);
   printf("Select figure from 1 to 3 ");
   int figure;
   scanf("%d",&figure);
   if(figure==1){
       firstFigure(n);
   }else if(figure==2){
       secondFigure(n);
   }else if(figure==3){
       thirdFigure(n);
   }else{
       return 1;
   }
    return 0;
}
