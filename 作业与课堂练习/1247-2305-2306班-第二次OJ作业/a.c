#include<stdio.h>

int main(){
	int n,r;
	while (scanf("%d %d",&n,&r)!=EOF){
		printf("%d\n",n/(-r));
	}
	
	return 0;
}
