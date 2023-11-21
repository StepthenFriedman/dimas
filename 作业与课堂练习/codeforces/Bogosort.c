#include <stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
	return *(int*)b-*(int*)a;
}

int main(){
    int t,n,i,j,min,a[10000];
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%d",&n);
        for (j=0;j<n;j++) scanf("%d",&a[j]);
        qsort(a,n,sizeof(int),cmp);
        for (j=0;j<n;j++) printf("%d ",a[j]);
        putchar('\n');
    }
    return 0;
}