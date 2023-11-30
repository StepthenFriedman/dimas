#include <stdio.h>
int isLucky(long long x){
    if (!(x%6)) return 1;
    int a=x%10,b=x%100,c=x%1000;
    if (!(a-6)||!(b-a-60)||!(c-b-600)) return 1;
    return 0;
}

int main(){
    long long i,j,n;
    while (~scanf("%lld",&n)){
        for (i=6,j=0;j<n;i++) if (isLucky(i)) j++;
        printf("%lld\n",--i);
    }
}