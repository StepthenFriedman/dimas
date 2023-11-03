#include <stdio.h>

int main(){
	int x=0, sum=0, a[1001]={0},i,j;
	double m;
	for (i=2;i<=10000000;i++){
		m=sqrt(i);sum=1;
		for (j=2;(double)j<m;j++) if (!(i%j)) sum+=j+(i/j);
		if ((int)m*(int)m==i) sum+=(int)m;
		if (sum<=1000) a[sum]=1;
	}j=0;
	for (i=1;i<=1000;i++) if (!a[i]) {
		printf("%d,",i);j++;
	}
	printf("j:%d",j);
	return 0;
}
