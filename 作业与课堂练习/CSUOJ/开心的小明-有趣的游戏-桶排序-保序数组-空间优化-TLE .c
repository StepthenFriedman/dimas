#include<stdio.h>

int main(){
	int n,i,j=0,k=1,sum,len,add,times;
	scanf("%d",&n);
	int a[n],max,min;
	scanf("%d",&a[0]);max=min=a[0];
	for(i=1;i<n;i++){
		scanf("%d",&a[i]);
		max=max>a[i]?max:a[i];
		min=min<a[i]?min:a[i];
	}
	len=max-min+1+n;
	int* busket=calloc(len,sizeof(int));
	for (i=0;i<n;i++) busket[a[i]-min]++;
	for (times=0;times<n;times++){
		while (!busket[i])i++;
		busket[i]--;add=i+min;
		while (!busket[a[i]])i++;
		busket[i]--;add+=a[i]+min;
		
	}/*
	sum=a[0]=a[0]+a[1];i=2;
	while (i<n||j<k-1){
		a[k]=(a[j]<a[i]||i>=n)?a[j++]:a[i++];
		sum+=a[k++]+=(a[j]<a[i]||i>=n)?a[j++]:a[i++];
	}*/
	printf("%d\n",sum);
	return 0;
}
