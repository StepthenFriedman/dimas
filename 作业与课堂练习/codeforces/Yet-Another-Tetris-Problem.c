#include <stdio.h>

int main(){
    int t,i,j,n,a,b,bool;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        bool=1;
        scanf("%d%d",&n,&a);
        a%=2;
        for (j=1;j<n;j++) {
            scanf("%d",&b);
            if ((b%2)!=a) bool=0;
        }
        if (bool) printf("YES\n");
        else printf("NO\n");
    }
    return 0;
}