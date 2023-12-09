#include<stdio.h>
int main()
{
	int n,m,i,j,k;
	while(scanf("%d %d",&n,&m)!=EOF)
	{
		if(!(m+n))break;
		int num=0;
		char arr[800][800];
		int x[800],y[800],h[800][800]={0};
		for(i=0;i<n;i++)scanf("%s",arr[i]);
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(arr[i][j]=='0')
				{
					x[num]=i;
					y[num]=j;
					num++;
			    }
			}
		}
		for(i=0;i<n;i++)
		{
			for(j=0;j<m;j++)
			{
				if(arr[i][j]=='0')
				{
					printf("0 ");
					continue;
				}
				h[i][j]=m+n;
				for(k=0;k<num;k++)
				{
					int a=((x[k]-i)>0?(x[k]-i):(i-x[k]))+((y[k]-j)>0?(y[k]-j):(j-y[k]));
					if(a<h[i][j])
					{
						h[i][j]=a;
						if(h[i][j]==1)break;
					}
				}
				printf("%d ",h[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}