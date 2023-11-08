#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

int main(){
	int n,i,j,k,sum;
	scanf("%d",&n);
	int a[n],b[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),cmp);
	sum=b[0]=a[0]+a[1];
	i=2;j=0;k=1;
	while (1){
		
		if (b[j]<a[i]||i>=n) b[k]=b[j++];
		else b[k]=a[i++];
		
		if (b[j]<a[i]||i>=n) b[k]+=b[j++];
		else b[k]+=a[i++];
		
		sum+=b[k];
		k++;
		
		if (i>=n&&j>=k-1) break;
	}
	
	printf("%d\n",sum);
	return 0;
	
	
}
