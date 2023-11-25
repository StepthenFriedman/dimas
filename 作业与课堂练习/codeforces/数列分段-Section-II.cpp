#include <stdio.h>
#include <limits.h>
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y

int main(){
    long long N,M,i,j;
    scanf("%lld%lld",&N,&M);
    long long arr[N],dp[M][M];
    for (i=0;i<N;i++) scanf("%lld",&arr[i]);
    for (i=1;i<N;i++) {
        for (j=1;j<M;j++){
            dp[j]=min(dp[j],dp[j-1]+arr[i]);
        }
    }
    for (j=0;j<M;j++) printf("%lld ",dp[j]);
    return 0;
}