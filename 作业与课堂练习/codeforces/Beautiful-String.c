#include <stdio.h>

int main(){
    long long int t,n,i,j,k,x,y;
    scanf("%lld",&t);
    for (i=0;i<t;i++){
        scanf("%lld%lld",&n,&k);
        for (j=1;j*(j+1)/2<k;j++);j--;
        x=n-2-j;y=n-(k-(j*(j+1)/2));
        for (j=0;j<n;j++){
            if (j==x||j==y) putchar('b');
            else putchar('a');
        }
        putchar('\n');
    }
    return 0;
}
