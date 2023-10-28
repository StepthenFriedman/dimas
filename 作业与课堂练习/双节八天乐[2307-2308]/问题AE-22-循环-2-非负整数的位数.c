#include <stdio.h>
int main(){
	int n,i;
	while (scanf("%d",&n)!=EOF){
		i=0;
		do {n/=10;i++;}while (n);
		printf("%d\n",i);
	}
	return 0;
}
