#include <stdio.h>

int main(){
    int n,i;long long int j;double e;
    while (1) {
        i=j=1;e=1.;
        scanf("%d",&n);
        for (;i<=n;i++){
            j*=i;
            e+=1./(double)j;
        }
        printf("%lf\n",e);
    }
    return 0;
}