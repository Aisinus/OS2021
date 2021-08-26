#include <stdio.h>
#include <stdlib.h>
int main(int argc, char* argv[])
{
    int n=atoi(argv[1]);
    for(int i=1;i<=n;i++){
        int n2=n-i;
        for(int j=1;j<=n2;j++){
            printf(" ");
        }
        for(int j=1;j<=i*2-1;j++){
            printf("*");
        }
        printf("\n");
    }
    return 0;
}
