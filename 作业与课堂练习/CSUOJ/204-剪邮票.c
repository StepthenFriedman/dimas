#include<stdio.h>
int a[13]={0}; 
int b[13]={0};
int count = 0,F;

//int bfs(int n,int i)//重要的是这个，判断是否五个相连通 
int bfs(int i)
{
	a[i] = 0;
	if(F != 4)
	{
		if(i - 1 >= 0 && (i - 1) % 4 != 3 && a[i-1] == 1)//该邮票与左边的邮票相邻 
		{
			F++;
			//bfs(n+1,i-1);
			bfs(i-1);
		}
		if(i + 1 < 12 && (i + 1) % 4 != 0 && a[i+1] == 1)////该邮票与右边的邮票相邻 
		{
			F++;
			//bfs(n+1,i+1);
			bfs(i+1);
		}
		if(i - 4 >= 0 && a[i-4] == 1) //该邮票与上面的邮票相邻 
		{
			F++;
			//bfs(n+1,i-4);
			bfs(i-4);
		}
		if(i + 4 < 12 && a[i+4] == 1) //该邮票与下面的邮票相邻 
		{
			F++;
			//bfs(n+1,i+4);
			bfs(i+4);
		}
	}
}

int printff(int k)
{
		int i;
		
		F = 0;
		for(i = 11; i >= 0; i--)
        {//赋值给 a 数组 
			a[i] = b[i];
		}
		
		//bfs(0,k);//调用函数，判断是否五个相连通
		bfs(k);//调用函数，判断是否五个相连通
		
		if(F == 4)
		{
			
			printf("第%d个\n",++count);
			
			for(i = 0; i < 12; i++)
			{
				printf("%d ",b[i]);
				if(i % 4 == 3)
					printf("\n");
			}
			
			printf("\n");
		}
}

int f(int k,int n)
{
	int i,j;
	if(n == 5)//如果已经选择了有5个 
	{
		//++count;
		printff(k);//进入测试，看是否满足联通 
	}
	else
		for(i = k; i < 12 ;i++)//这里相当于是一个剪枝，避免了重复
		{
			if(b[i] == 0)
			{
				b[i] = 1;
				f(i,n+1);
				b[i] = 0;
			}
		}
}

int main()
{
	f(0,0);
}