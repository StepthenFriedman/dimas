#include <stdio.h>

int isAs(int *a,int *b){
    return (a[1]<b[0]);
}

long long int count(int x){
    long long int sum=0;
    for (int i=1;i<x;i++) sum+=i;
    return sum;
}

int main(){
    int t,n,i,indx,j,x,tmp,*p1,*p2,arr[200000][2],end;
    long long int res,selfas;
    scanf("%d",&t);
    for (selfas=i=0;i<t;i++){
        scanf("%d",&n);
        scanf("%d",&arr[indx][0]);
        tmp=arr[indx][0];end=0;
        if (n==1) arr[indx][1]=arr[indx][0];
        else{
            for (j=1;j<n;j++) {
                scanf("%d",&x);
                if (x>tmp&&!end) selfas+=end=1;
                tmp=x;
                if (j==n-1) arr[indx][1]=x;
            }
        }
        if (!end) indx++;
    }
    res=count(selfas)*2+selfas+(selfas*(t-selfas)*2);
    for (p1=&arr[0][0];p1<&arr[indx][0];p1+=2) for (p2=p1;p2<&arr[indx][0];p2+=2) {
        res+=isAs(p1,p2)+isAs(p2,p1)*(p1!=p2);
    }
    printf("%lld\n",res);
    return 0;
}