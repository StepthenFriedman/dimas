#include <stdio.h>
#include <math.h>

int a[100000];

void x(){
    int i,*j,amount,sqt,*st=a;
    a[0]=2;
    for (amount=1,i=3;amount<100000;i+=2){
        sqt=sqrt(i);
        for (j=st;*j<=sqt;j++) if (!(i%*j)) goto next;
        a[amount++]=i;
        next:;
    }
}
int main() {
    int i,n;
    x();
    while (~scanf("%d",&n)) for (i=0;a[i]<=n;i++) printf("%d\n",a[i]);
    return 0;
}