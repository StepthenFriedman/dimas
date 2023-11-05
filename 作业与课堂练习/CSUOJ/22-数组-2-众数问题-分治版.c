#include <stdio.h>
#include <stdlib.h>

int cmp(const int*a,const int*b){
	return (*(int*) a)-(*(int*) b);
}

void most(int* h, int* t, int* max, int* num){
	int *m=h+((t-h-1)/2), *hm, *tm;
	for (hm=m-1;(hm>=h)&&((*hm)==(*m));hm--);
	for (tm=m+1;(tm<=t)&&((*tm)==(*m));tm++);
	if (*max<(tm-hm-1)) {*max=tm-hm-1;*num=*(tm-1);}
	if (hm-h+1>*max) most(h,hm,max,num);
	if (t-tm+1>*max) most(tm,t,max,num);
}
    
int main(){
	int n=0,i,arr[100000],max=1,num;
	while (scanf("%d",&n)!=EOF){
		max=1;num=arr[0];
		for (i=0;i<n;i++) scanf("%d",&arr[i]);
		qsort(arr,n,sizeof(int),cmp);
		most(&arr[0],&arr[n-1],&max,&num);
		printf("%d\n%d\n",num,max);
	}
	return 0;
}
