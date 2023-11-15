#include <stdio.h>

int main(){
    int n,i,j,sum;
    for (i=2;i<=5000;i++){
        sum=0;
        for (j=1;j<i;j++){
            if (!(i%j)) sum+=j;
        }
        if (i==sum) printf("%d\n",i);
    }
    return 0;
}