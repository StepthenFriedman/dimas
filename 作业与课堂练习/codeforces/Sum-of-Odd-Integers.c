#include <stdio.h>

int main(){
    long long int t,n,k,i;
    scanf("%lld",&t);
    for (i=0;i<t;i++){
        scanf("%lld%lld",&n,&k);
        if (n<k*k||(n%2)!=(k%2)) printf("NO\n");
        else printf("YES\n");
    }
    return 0;
}