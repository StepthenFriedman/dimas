#include<stdio.h>

int main(){
	int n,i,j=0,k=1,sum;
	scanf("%d",&n);
	int a[n];
	for(i=0;i<n;i++) scanf("%d",&a[i]);
	i=0;
	while (i<n-1){
		if (a[i]>a[i+1]){
			a[i]=a[i]^a[i+1];
			a[i+1]=a[i]^a[i+1];
			a[i]=a[i]^a[i+1];
			if (i) i--;
		}else i++;
	}
	sum=a[0]=a[0]+a[1];i=2;
	while (i<n||j<k-1){
		a[k]=(a[j]<a[i]||i>=n)?a[j++]:a[i++];
		sum+=a[k++]+=(a[j]<a[i]||i>=n)?a[j++]:a[i++];
	}
	printf("%d\n",sum);
	return 0;
}
