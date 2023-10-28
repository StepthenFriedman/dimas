#include <stdio.h>
int main(){
	int n,i=0;
	while (scanf("%d",&n)!=EOF){
		i=-1;
		while (n){
			n>>=1;i++;
		}
		printf("%d\n",i);
	}
	return 0;
}
