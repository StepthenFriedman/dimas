#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

int main(){
	int n,i,j=0,k=1,sum;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmp);
	sum=a[0]=a[0]+a[1];i=2;
	while (i<n||j<k-1){
		a[k]=(a[j]<a[i]||i>=n)?a[j++]:a[i++];
		sum+=a[k++]+=(a[j]<a[i]||i>=n)?a[j++]:a[i++];
	}
	printf("%d\n",sum);
	return 0;
}
