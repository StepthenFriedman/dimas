#include <stdio.h>

int main(){
	long long int n,i;
	int rem=1;
	while (scanf("%lld",&n)!=EOF) {
		if (n>=2009) {
			printf("%d\n",0);
			continue;
		}
		rem=1;
		for (i=1;i<=n;i++) {
			rem*=i;while (rem>=2009) rem-=2009;
		}
		printf("%d\n",rem);
	}
	return 0;
}
