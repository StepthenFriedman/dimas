#include<stdio.h>

int main()
{
	int n,i,j;
	while(scanf("%d", &n)!=EOF){
		for (i=n;i>0;i--) printf("%*c\n",i+1,'*');
		for (i=0;i<=n;i++) putchar('*');
		printf("\n");
		for (i=n-1;i>0;i--) printf("%*c\n",i+1,'*');
		printf("*\n\n");
	}
	return 0;
}
