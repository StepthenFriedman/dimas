#include <stdio.h>

int arr[10000000];
int main(){
    int t,i;
    long long int n,j,indx,p,q;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%lld",&n);
        j=indx=1;arr[0]=0;
        while (j<=(n/2)) {
            p=n/j;q=n%j;
            if (p>q) arr[indx++]=j++;
            else j+=q/p;
        }
        printf("%lld\n",indx+1);
        for (j=0;j<indx;j++) printf("%d ",arr[j]);printf("%lld\n",n);
    }
    return 0;
}