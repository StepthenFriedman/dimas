#include<stdio.h>
int main()
{
	int num = 7;
	int count = 0;
	while (num)
	{
		num = num&(num - 1);
		count++;
	}
	printf("num��1�ĸ�����%d\n", count);
	return 0;
}
