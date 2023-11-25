#include <stdio.h>

int min(int x,int y){
    return x<y?x:y;
}

int main(){
    int t,n,m,i,j,sum;
    scanf("%d",&t);
    for (i=0;i<t;i++) {
        scanf("%d%d",&n,&m);
        for (sum=0,j=1;j<=n;j++) sum+=min(n-j+1,m*j);
        printf("%d\n",sum);
    }
    return 0;
}