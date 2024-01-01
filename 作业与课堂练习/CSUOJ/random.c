#include<stdio.h>
#include<stdlib.h>
#include<time.h>

int main(){
    int x,i=2;
    srand(time(NULL));
    while(i--){
        x=rand()%11+1;
        printf("%d ",x);
    }
    return 0;
}