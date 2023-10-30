#include<stdio.h>

int main()
{
	int n,i,j;
	while(scanf("%d", &n)!=EOF){
		for (i=n;i>0;i--){
			for (j=0;j<i;j++) {
				putchar(' ');
			}
			printf("*\n");
		}
		for (i=0;i<=n;i++) putchar('*');
		printf("\n");
		for (i=n-1;i>0;i--){
			for (j=0;j<i;j++) {
				putchar(' ');
			}
			printf("*\n");
		}
		printf("*\n\n");
	}
	return 0;
}
