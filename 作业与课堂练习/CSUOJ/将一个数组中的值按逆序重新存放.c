#include<stdio.h>

int main(){
	int n,i,b;
	while (~scanf("%d",&n)){
		int a[n];
		for(i=0;i<n;i++) scanf("%d",&a[i]);
		for(i=n-1;i>-1;i--) printf("%d ",a[i]);
		putchar('\n');
	}
	return 0;
}
