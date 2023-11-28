#include <stdio.h>

const long long LONG_LONG_MAX=9223372036854775807;

int max(int x,int y){
    return x>y?x:y;
}
void mini(long long int *x,long long int y){
    *x=*x<y?*x:y;
}

int main(){
    long long N,M,i,j,k,l,min=LONG_LONG_MAX,a,cmp;
    scanf("%lld%lld",&N,&M);
    long long dp[M+1][N+1];
    dp[0][0]=0;
    for (i=0;i<N;i++){
        scanf("%lld",&a);
        dp[0][i+1]=dp[0][i]+a;
    }
    for (i=1;i<M-1;i++) {
        l=k=i-1;
        for (j=i;j<N;j++){
            dp[i][j]=LONG_LONG_MAX;
            for (l=k;l<j;l++){
                cmp=max(dp[i-1][l],dp[0][j]-dp[0][l]);
                if (dp[i][j]>cmp){
                    k=l;dp[i][j]=cmp;
                }
            }
        }
    }
    for (j=M-1;j<N;j++) mini(&min, max(dp[M-2][j],dp[0][N]-dp[0][j]));
    for (i=0;i<M-1;i++) {for (j=0;j<N;j++) printf("%lld ",dp[i][j]); putchar('\n');}
    printf("%lld\n",min);
    return 0;
}