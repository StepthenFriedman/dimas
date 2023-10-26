#include <stdio.h>

int main(){
	int m,n,i;
	while (scanf("%d %d",&m,&n)!=EOF){
		int sum_sq=0,sum_cube=0;
		for (i=m;i<=n;i++) {
			if (i%2) sum_cube+=i*i*i;
			else sum_sq+=i*i;
		}
		printf("%d %d\n",sum_sq,sum_cube);
	}
	return 0;
}
