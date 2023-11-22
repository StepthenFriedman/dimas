#include <stdio.h>


int main(){
    int t,n,i,j,tmp,arr[100000],indx;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%d",&n);
        tmp=1;indx=2;arr[0]=0;arr[1]=1;
        for (j=n-1;j>0;j--) if ((n/j)!=tmp) arr[indx++]=tmp=(n/j);
        printf("%d\n",indx);
        for (j=0;j<indx;j++) printf("%d ",arr[j]);putchar('\n');
    }
    return 0;
}