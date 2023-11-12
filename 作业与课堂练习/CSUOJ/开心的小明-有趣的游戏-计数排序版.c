#include<stdio.h>
#include <stdlib.h>

int main(){
	int n,i,j,sum=0,len,add,times;
	scanf("%d",&n);
	int a[n],max,min;
	scanf("%d",&a[0]);max=min=a[0];
	for(i=1;i<n;i++){
		scanf("%d",&a[i]);
		max=max>a[i]?max:a[i];
		min=min<a[i]?min:a[i];
	}
	len=max-min+1+n;
	int* sort=calloc(len,sizeof(int));
	for (i=0;i<n;i++) sort[a[i]-min]++;
	i=0;j=max-min+1;
	for (times=0;times<n-1;times++){
		while (!sort[i])i++;
		if (i<=max-min){
			sort[i]--;add=i+min;
		}
		else {
			add=sort[i];sort[i]=0;
		}
		while (!sort[i])i++;
		if (i<=max-min){
			sort[i]--;add+=i+min;
		}
		else {
			add+=sort[i];sort[i]=0;
		}
		sum+=add;
		if (add>max) sort[j++]=add;
		else sort[add-min]++;
	}
	free(sort);
	printf("%d\n",sum);
	return 0;
}
