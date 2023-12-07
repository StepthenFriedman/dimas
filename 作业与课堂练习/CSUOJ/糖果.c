#include <stdio.h>

long long cn3(long long x){
    if (x<3) return 0;
    return x*(x-1)*(x-2)/6;
}

int main(){
    long long n,a,b,c;
    while (~scanf("%lld",&n)){
        a=b=c=n/3;
        if (n%3==2) a++,b++;
        else if (n%3==1) a++;
        printf("%lld\n",(a*b*c+cn3(a)+cn3(b)+cn3(c))%1000000007LL);
    }
}