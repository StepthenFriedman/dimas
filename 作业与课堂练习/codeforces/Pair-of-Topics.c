#include <stdio.h>
#include <stdlib.h>
int cmp(const void *a,const void *b){
	return *(int*)b-*(int*)a;
}
int a[300000];
int main(){
    int n,i,j,b;long long int sum=0;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&a[i]);
    for (i=0;i<n;i++) {
        scanf("%d",&b);a[i]-=b;
    }
    qsort(a, n, sizeof(int), cmp);
    for (i=0,j=n-1;i<j;i++){
        for (;a[j]+a[i]<=0;j--);
        if (i>=j) break;
        sum+=j-i;
    }
    printf("%lld\n",sum);
    return 0;
}