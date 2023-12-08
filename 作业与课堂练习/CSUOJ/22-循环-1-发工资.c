#include <stdio.h>

int main(){
	int n,ai,i;
	int parm[3];
	while (scanf("%d",&parm[0])!=EOF) {
		int sum=0;
		for (i=0;i<n;i++){
			scanf("%d",&ai);
			sum+=ai/100;ai%=100;
			sum+=ai/50;ai%=50;
			sum+=ai/10;ai%=10;
			sum+=ai/5;ai%=5;
			sum+=ai/2;ai%=2;
			sum+=ai;
		}
		printf("%d\n",sum);
	}
	return 0;
}
