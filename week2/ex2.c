
#include <stdio.h>
#include <string.h>
int main()
{
    printf("Print your string ");
    char Name[100];
    fgets(Name,100,stdin);
    for(int i=strlen(Name);i>=0;i--){
        printf("%c",Name[i]);
    }
    return 0;
}
