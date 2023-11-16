#include <stdio.h>
#include <math.h>

int prime[5]={0,2,3,5,7};

int main(){
    int i,j,k,l,m,res,sum,count=0;
    for (i=1;i<5;i++) printf("%d\n",prime[i]);
    for (i=0;i<3;i++) for (j=0;j<5;j++) if (!(i+j)||j) for (k=1;k<5;k++) for (l=2;l<5;l+=2){
        for (m=(res=prime[i]*1000+prime[j]*100+prime[k]*10+prime[l])-1;m>1;m--) if (!(res%m)) goto next;
        for (m=(sum=prime[i]+prime[j]+prime[k]+prime[l])-1;m>1;m--) if (!(sum%m)) goto next;
        printf("%d\n",res);next:;
    }
    return 0;
}