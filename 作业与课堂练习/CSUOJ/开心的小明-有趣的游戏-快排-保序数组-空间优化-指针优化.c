#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

int main(){
	int n,sum;
	scanf("%d",&n);
	int a[n],*i=&a[0],*j=&a[0],*k=&a[1],*end=&a[n-1];
	for(;i<=end;i++) scanf("%d",i);
	qsort(a,n,sizeof(int),cmp);
	sum=a[0]=a[0]+a[1];i=&a[2];
	while (i<=end||j<k-1){
		*k=(*j<*i||i>end)?*(j++):*(i++);
		sum+=*(k++)+=(*j<*i||i>end)?*(j++):*(i++);
	}
	printf("%d\n",sum);
	return 0;
}
