#include <stdio.h>
#include<bits/stdc++.h>

int check(long long x,long long *arr,long long n,long long sep){
    long long temp,i;
    for (temp=i=0;i<n;i++){
        temp+=arr[i];
        if (temp>x){
            temp=arr[i];
            sep--;
        }
        if (i==n-1) if (temp>x) return 0;
    }
    return sep>0;
}

int main(){
    long long N,M,i,left,right=0,mid;
    scanf("%lld%lld",&N,&M);
    long long arr[N];
    for (i=0;i<N;i++){
        scanf("%lld",&arr[i]);
        left=std::max(left,arr[i]),right+=arr[i];
    }
    while (left < right) {
        mid =(right + left) / 2;
        //printf("%lld %lld %lld\n",left,mid,right);
        if (check(mid,arr,N,M)) {
            right = mid;
        } else left=mid+1;
    }
    printf("%lld\n",left);
    return 0;
}