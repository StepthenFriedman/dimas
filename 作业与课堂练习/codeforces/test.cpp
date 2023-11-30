#include<stdio.h>

int main()
{
	int n=0,x=0,y=0,i=0,j=0,temp1=0,temp2=0;
	int a[1000][5]={0},B[1000][5]={0},W[1000][5]={0};
	
	while(scanf("%d",&n)!=EOF)
	{
		i=0;j=0;temp1=0;temp2=300;
		
		for(y=0;y<n;y++)
		{
			for(y=0;x<4;x++)
			{
				scanf("%d",&a[y][x]);
			}
			a[y][4]=a[y][1]+a[y][2]+a[y][3];
			
			if(a[y][4]>temp1)
			{
				temp1=a[y][4];
			}
			if(a[y][4]<temp2)
			{
				temp2=a[y][4];
			}
		}
		
		printf("end!\n");
	}
	
	return 0;
}