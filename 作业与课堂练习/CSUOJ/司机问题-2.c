#include<stdio.h>
#include<stdlib.h>
#pragma GCC optimize ("O2")

int cmp(const void *a,const void *b){return *(int*)a-*(int*)b;}
int cmp2(const void *a,const void *b){return *(int*)b-*(int*)a;}
int a[110]={0},b[110]={0};

int main(){
    int n,d,r,i,sum;
    while(~scanf("%d%d%d",&n,&d,&r)){
        sum=0;
        for(i=0;i<n;i++)scanf("%d",&a[i]);
        for(i=0;i<n;i++)scanf("%d",&b[i]);
        qsort(a,n,sizeof(int),cmp);
        qsort(b,n,sizeof(int),cmp2);
        for(i=0;i<n;i++) sum+=((a[i]+b[i])-d)*r;
        printf("%d\n",sum);
    }
    return 0;
}