#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

int main(){
	int n,i,j,k,sum;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	qsort(a,n,sizeof(int),cmp);
	sum=a[0]=a[0]+a[1];
	i=2;j=0;k=1;
	while (i<n||j<k-1){
		
		if (a[j]<a[i]||i>=n) a[k]=a[j++];
		else a[k]=a[i++];
		
		if (a[j]<a[i]||i>=n) a[k]+=a[j++];
		else a[k]+=a[i++];
		
		sum+=a[k++];
	}
	
	printf("%d\n",sum);
	return 0;
}
