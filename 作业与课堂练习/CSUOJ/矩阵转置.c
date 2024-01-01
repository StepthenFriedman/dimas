#include<stdio.h>

int main(){
    int N,i,j;
    while (~scanf("%d",&N)){
        long long init[N][N];
        for (i=0;i<N;i++) for (j=0;j<N;j++) scanf("%lld",&init[i][j]);
        for (j=0;j<N;j++) {for (i=0;i<N;i++) printf("%lld ",init[i][j]);putchar('\n');}
    }
    return 0;
}