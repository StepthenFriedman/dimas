#include <stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

int main(){
    int t,n,i,j,arr[100000],k;
    scanf("%d",&t);
    for (i=0;i<t;i++){
        scanf("%d",&n);k=n;
        for (j=0;j<n;j++) scanf("%d",&arr[j]);
        qsort(arr,n,sizeof(int),cmp);
        for (j=1;j<n;j++) k-=(arr[j]==arr[j-1]);
        printf("%d\n",k);
    }
    return 0;
}