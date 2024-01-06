#include <stdio.h>
#include <stdlib.h> 
 
#define MAXN 500005
long long  count=0;
 
int data[MAXN]={0};
int merge[MAXN]={0};
 
void Merge(int merge[],int a[],int left,int right,int middle)
{
	int i=left,j=middle+1;
	int k=left;
	while(i<=middle&&j<=right)
	{
		if(a[i]<=a[j])
		{
			merge[k++]=a[i++];
		}
		else
		{
			merge[k++]=a[j++];
			count+=middle-i+1;
            printf("add:%d\n",middle-i+1);
		}
	}
	while(i<=middle)merge[k++]=a[i++];
	while(j<=right)merge[k++]=a[j++];
	i=0;
	for(i=left;i<=right;i++)a[i]=merge[i];
}
//合并排序算法
 
void Mergesort(int a[],int left,int right)
{
	if(left<right)
	{
		int middle=(left+right)>>1;//位运算右移一位相当于除2
		Mergesort(a,left,middle);
		Mergesort(a,middle+1,right);
		Merge(merge,a,left,right,middle);
    }
} 
 
int main()
{  
	//第一行，一个数 n，表示序列中有 n个数。
	int n;
	scanf("%d",&n); 
	//第二行 n 个数，表示给定的序列。序列中每个数字不超过 10^9。 
	for(int i=0;i<n;i++)
		scanf("%d",&data[i]); 
		
	Mergesort(data,0,n-1);
		
	printf("%lld\n",count); 
	
    return  0;
}