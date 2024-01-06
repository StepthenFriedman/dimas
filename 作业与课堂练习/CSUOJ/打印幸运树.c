#include <stdio.h>
#include <stdlib.h>

int main(){
    int n,i,j;
    while (~scanf("%d",&n)){
        for (i=0;i<=n;i++){
            printf("%*c",n+1-i,'*');
            for (j=0;j<i*2;j++) putchar('*');
            putchar('\n');
        }
        for (i=0;i<n;i++) printf("%*c\n",n+1,'*');
    }
    return 0;
}