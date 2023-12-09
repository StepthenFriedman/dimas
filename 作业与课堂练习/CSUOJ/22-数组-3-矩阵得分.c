#include <stdio.h>

long long max(long long x,long long y){
    return x>y?x:y;
}
long long arr[510][510];
long long res[510][510];

int main(){
    long long n,m,i,j;
    while (~scanf("%lld%lld",&n,&m)){
        for (i=0;i<n;i++) for (j=0;j<m;j++) scanf("%lld",&arr[i][j]);
        res[0][0]=arr[0][0];
        for (i=0;i<n;i++) for (j=0;j<m;j++){
            if (i&&!j) res[i][j]=res[i-1][j]+arr[i][j];
            else if (j&&!i) res[i][j]=res[i][j-1]+arr[i][j];
            else res[i][j]=max(res[i-1][j],res[i][j-1])+arr[i][j];
        }
        for (i=0;i<n;i++){
            for (j=0;j<m;j++) printf("%lld ",res[i][j]);
            putchar('\n');
        }
    }
}
