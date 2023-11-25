#include <stdio.h>
long long int add(int x){
    return (1+(long long)x)*(long long)x/2;
}

int main(){
    int t,n,m,i,j,k;
    scanf("%d",&t);
    for (i=0;i<t;i++) {
        scanf("%d%d",&n,&m);
        k=n/(m+1);
        printf("%lld\n",add(k)*(long long)m+add(n-k));
    }
    return 0;
}