#include <stdio.h>
#include <math.h>

int main(){
    int t,i;
    long long int n,x,j,indx,p,q;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%lld",&n);
        x=(long long int)((sqrt((double)(1+4*n))-1.)/2.);
        indx=x*2+1;
        if (n>=x*(x+2)) indx++;
        j=1;
        printf("%lld\n0 ",indx);
        while (j<=(n/2)) {
            p=n/j;q=n%j;
            if (p>q) printf("%lld ",j++);
            else j+=q/p;
        }printf("%lld\n",n);
    }
    return 0;
}