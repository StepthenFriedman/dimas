#include <stdio.h>

int main(){
	long int n,m,k;
	while (scanf("%ld %ld %ld",&n,&m,&k)!=EOF){
		if ((n-m)%k) printf("UnHappy!\n");
		else if (n<=m) printf("UnHappy!\n");
		else printf("Happy!\n");
	}
	return 0;
}
