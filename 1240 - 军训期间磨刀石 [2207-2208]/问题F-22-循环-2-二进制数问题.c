#include <stdio.h>

int main(){
	int n,i,A,sum1,j;
	while (scanf("%d",&n)!=EOF){
		A=0;
		for (i=1;i<=n;i++) {
			j=i;sum1=0;
			while (j) {
				if (j%2) sum1++;
				else sum1--;
				j>>=1;
			}
			if (sum1>0) A++;
		}
		printf("%d %d\n",A,n-A);
	}
	return 0;
}
