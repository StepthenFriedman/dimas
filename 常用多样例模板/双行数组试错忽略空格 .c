#include <stdio.h>
int main(){
	int n;char ipt[1000];
	while (scanf("%d",&n)!=EOF){
		getchar();
		gets(ipt);
		printf("%d: %s\n",n,ipt);
	}
	return 0;
}
