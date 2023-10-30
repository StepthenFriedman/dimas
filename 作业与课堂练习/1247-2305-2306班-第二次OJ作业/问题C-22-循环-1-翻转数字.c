#include<stdio.h>
int reverse(int x)
{
	int rev = 0;
	while(x)
	{
		rev = rev * 10 + x % 10;
		x /= 10;
	}
	return rev;
}
int main()
{
	int num = 0;
	while(scanf("%d", &num)!=EOF){
	num = reverse(num);
	printf("%d\r\n", num);}
	return 0;
}
