#include <stdio.h>

int dic(int x,int m){
    if (x>=m) return (x/m)+(!!(x%m));return 2;
}

int main(){
    int t,n,i,j,min,x,a,tmp;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%d%d",&n,&x);
        for (min=1e9,j=0;j<n;j++) {
            scanf("%d",&a);
            tmp=dic(x,a);
            min=min<tmp?min:tmp;
        }
        printf("%d\n",min);
    }
    return 0;
}