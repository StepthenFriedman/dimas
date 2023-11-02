#include<stdio.h>

int main(){
	int a,b,c;
	while (scanf("%d %d %d",&a,&b,&c)!=EOF)printf("%d\n",(a=(a<b)?b:a,a=(a>c)?a:c));
	return 0;
}
