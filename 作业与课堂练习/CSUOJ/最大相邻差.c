#include <stdio.h>

long long abs(long long a, long long b){
    return (a>b)?a-b:b-a;
}

int main(){
    long long int n,x,y,max,i;
    while (~scanf("%lld",&n)){
        max=-9223372036854775807;
        scanf("%lld",&x);
        for (i=1;i<n;i++){
            scanf("%lld",&y);
            if (max<abs(y,x)) max=abs(y,x);
            x=y;
        }
        printf("%lld\n",max);
    }
}