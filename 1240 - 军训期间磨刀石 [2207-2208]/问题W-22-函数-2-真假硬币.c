#include <stdio.h>

int main(){
	int n,i;
	while (1){
		scanf("%d",&n);
		if (n==0) break;
		i=0;
		while (n>1) {
			n=(n/3)+((n%3)>0);i++;
		}
		printf("%d\n",i);
	}
	return 0;
}
