#include <stdio.h>
#include <stdlib.h>

void swap(int* a, int* b){
    int c=*a;
    *a=*b;
    *b=c;
}

int main()
{
    int a,b;
    printf("print first int ");
    scanf("%d", &a);
    printf("print second int ");
    scanf("%d", &b);
    swap(&a,&b);
    printf("%d\n",a);
    printf("%d\n",b);
    return 0;
}
