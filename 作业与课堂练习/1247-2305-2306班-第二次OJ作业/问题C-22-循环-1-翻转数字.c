#include<stdio.h>
int reverse(int x){
	int rev=0;
	while(x){
		rev=rev*10 + x%10;
		x/=10;
	}
	return rev;
}
int main()
{
	int num = 0;
	while(scanf("%d", &num)!=EOF) printf("%d\n", reverse(num));
	return 0;
}
