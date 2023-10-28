#include <stdio.h>

int main(){
	long long int n,m,y;
	while (1){
		scanf("%lld %lld",&n,&m);
		if (n+m==0) break;
		else if (m%2|2*n>m|m>4*n) printf("Error\n");
		else { y=(m/2)-n; printf("%lld %lld\n",n-y,y);}
	}
	return 0;
}
