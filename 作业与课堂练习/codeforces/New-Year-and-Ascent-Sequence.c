#include <stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

long long int count(int x){
    long long int sum=0;
    for (int i=1;i<x;i++) sum+=i;
    return sum;
}

int main(){
    int t,n,i,indx,j,x,tmp,*p1,*p2,a[100000],b[100000],end;
    long long int res,selfas;
    scanf("%d",&t);
    for (indx=selfas=i=0;i<t;i++){
        scanf("%d",&n);
        scanf("%d",&a[indx]);
        tmp=a[indx];end=0;
        if (n==1) {
            b[indx]=a[indx];indx++;
        }
        else{
            for (j=1;j<n;j++) {
                scanf("%d",&x);
                if (x>tmp&&!end) selfas+=end=1;
                tmp=x;
                if (j==n-1) b[indx]=x;
            }
            if (!end) indx++;
        }
    }
    res=count(selfas)*2+selfas+(selfas*(t-selfas)*2);
    qsort(a,indx,sizeof(int),cmp);
    qsort(b,indx,sizeof(int),cmp);
    for (i=j=0;i<indx;i++){
        while (b[j]<a[i]&&j<indx) j++;
        res+=j;
    }
    printf("%lld\n",res);
    return 0;
}