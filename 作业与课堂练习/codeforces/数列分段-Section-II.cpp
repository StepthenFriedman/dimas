#include <stdio.h>
#include <limits.h>
#define min(x,y) x<y?x:y
#define max(x,y) x>y?x:y

int main(){
    long long N,M,i,j,k,l,min;
    scanf("%lld%lld",&N,&M);
    long long arr[N],add[N+1],dp[M][N];
    add[0]=0;
    for (i=0;i<M;i++) for (j=0;j<N;j++) dp[i+1][j]=0;
    for (i=0;i<N;i++){
        scanf("%lld",&arr[i]);
        add[i+1]=add[i]+arr[i];
    }
    for (i=1;i<M;i++) {//of the times of serverance
        for (j=i;j<N;j++){//of the last place of severance.
            min=LONG_LONG_MAX;
            for (k=i-1;k<j;k++){//of the last place of severance.
                long long temp=max(dp[i-1][k],add[j]-add[k]);
                min=min<temp?min:temp;
            }
            dp[i][j]=min;
        }
    }
    for (j=0;j<=N;j++) printf("%lld ",add[j]); putchar('\n');
    for (i=0;i<M;i++) {for (j=0;j<N;j++) printf("%lld ",dp[i][j]); putchar('\n');}
    return 0;
}