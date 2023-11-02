#include <stdio.h>
int main(){
	int n,i,a=0,b=1;
	while (scanf("%d",&n)!=EOF){
		printf("0, 1");
		for (i=0;i<n-2;i++){
			b=a+b;a=b-a;
			printf(", %d",b);
		}
	}
	return 0;
}
