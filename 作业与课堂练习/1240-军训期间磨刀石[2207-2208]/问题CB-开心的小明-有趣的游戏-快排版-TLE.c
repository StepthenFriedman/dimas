#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}
int main(){
	int n,i,b;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++){
		scanf("%d",&a[i]);
	}
	qsort(a,n,sizeof(int),cmp);
	b=a[0]+a[1];
	for(i=0;i<n-2;i++){
		a[i+1]=a[i]+a[i+1];
		qsort(a,n,sizeof(int),cmp);
		b=b+a[i+1]+a[i+2];
	}
	printf("%d",b);
	return 0;
}
