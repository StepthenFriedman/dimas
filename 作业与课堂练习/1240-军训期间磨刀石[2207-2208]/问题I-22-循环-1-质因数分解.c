#include <stdio.h>

int main(){
	long long int n,i;
	while (scanf("%lld",&n)!=EOF) {
		double sqt=sqrt(n);
		if (n%2==0) {
			printf("%lld\n",(n/2));continue;
		}
		for (i=3;(double)i<sqt;i+=2){
			if (n%i==0) {
				printf("%lld\n",(n/i));break;
			}
		}
	}
	return 0;
}
