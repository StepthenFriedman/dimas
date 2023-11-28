#include <stdio.h>

int check(long long x,long long *sum,long long n){
    long long temp;
    for (long long i=0;i<n;i++){

    }
}

int main(){
    long long N,M,i,left,right;
    scanf("%lld%lld",&N,&M);
    long long arr[N],sum[N+1];
    left=sum[0]=0;
    for (i=0;i<N;i++){
        scanf("%lld",&arr[i]);
        sum[i+1]=sum[i]+arr[i];
    }
    right=sum[N];

}