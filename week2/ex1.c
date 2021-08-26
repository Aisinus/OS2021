#include <stdio.h>
#include <limits.h>
#include <float.h>
int main(){
 int maxInt = INT_MAX;
 float maxFloat = FLT_MAX;
 double maxDouble = DBL_MAX;
 printf("%d, %f, %f\n", maxInt, maxFloat, maxDouble);
 printf("%lu, %lu, %lu\n", sizeof(maxInt), sizeof(maxFloat), sizeof(maxDouble));
 return 0;
}
