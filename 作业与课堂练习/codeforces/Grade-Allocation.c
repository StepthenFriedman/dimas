#include <stdio.h>

int main(){
    int t,n,m,i,j,a,sum;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%d%d",&n,&m);
        for (sum=j=0;j<n;j++) {
            scanf("%d",&a);
            sum+=a;
        }
        printf("%d\n",m<sum?m:sum);
    }
    return 0;
}