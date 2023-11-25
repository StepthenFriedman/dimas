#include <stdio.h>
long long int add(int x){
    return (1+(long long)x)*(long long)x/2;
}

int min(int x,int y){
    return x<y?x:y;
}

int main(){
    int t,n,m,i,j,k;long long int sum;
    scanf("%d",&t);
    for (i=0;i<t;i++) {
        scanf("%d%d",&n,&m);
        for (sum=0,j=1;j<=n;j++) sum+=min(n-j+1,m*j);
        k=n/(m+1);
        printf("%d\n",sum==add(k)*m+add(n-k));
    }
    return 0;
}