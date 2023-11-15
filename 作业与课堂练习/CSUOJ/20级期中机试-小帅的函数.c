#include <stdio.h>

int main(){
    int x;
    while (~scanf("%d",&x))printf("%d\n",(x<1)?(x*x):(x<10)?(2*x-1):(3*x-12));
    return 0;
}