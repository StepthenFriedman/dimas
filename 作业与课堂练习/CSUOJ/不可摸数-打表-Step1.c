#include <stdio.h>

int main(){
	int sum=0, a[10001],i,j;
	double m;
	for (i=1;i<=10000;i++){
		m=sqrt(i);sum=1;
		for (j=2;(double)j<m;j++) if (!(i%j)) sum+=j+(i/j);
		if ((int)m*(int)m==i) sum+=(int)m;
		a[i]=sum;
	}
	for (i=1;i<=10000;i++){
		printf("%d, ",a[i]);
	}
	return 0;
}
