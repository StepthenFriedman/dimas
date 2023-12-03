/*
题目描述
小南想要绘制一个金字塔。金字塔的图案由正三角形和倒三角形堆叠而成，共计n个。具体的绘制方法如下：
（1）每个三角形由*，/，\和-组成，分别代表三角形的顶点和三条边。
（2）第一行只包含一个正三角形，其余各行的三角形按照“正三角形、倒三角形、正三角形、倒三角形，……”的顺序排列。
（3）除最后一行外，每一行的三角形比上一行多2个。
金字塔中三角形的个数n定为多少好呢？小南想到一个有趣的斐波那契数列（Fibonacci sequence），其值从第0项开始依次为1,1,2,3,5,8,13,21,34,55,89,…。小南让老师给出一个正整数x，然后在斐波那契数列中找到不小于x的最小的斐波那契数对应的位置作为n，你能根据老师给出的x，帮小南编写程序绘制出相应的金字塔图案吗？（说明：斐波那契数列中1的位置为1，2的位置为2，3的位置为3，5 的位置为4，以此类推。）
输入
多个样例。每个样例输入一个正整数x(1≤x≤105)，表示老师给出的正整数。
输出
对于每个样例输出对应的图案，注意每行的末尾没有多余的空格。
*/

#include<stdio.h>
#include<math.h>
int main()
{
	long long a[2],x,i,j,num,row,rem;
	while(scanf("%lld",&x)!=EOF){
		if (x==1) num=1;
		else if (x==2) num=2;
		else {
			a[0]=1;a[1]=2;
			for(i=2;a[!(i%2)]<x;i++) a[i%2]=a[i%2]+a[!(i%2)];
            num=i;
		}
        row=(long long)sqrt(num);
        while (row*row<num) row++;
        rem=row*row-num;rem=2*row-1-rem;
        printf("%*c\n",2*(int)(row)+1,'*');
        for (i=0;i<row-!!(rem);i++){
            printf("%*c",2*(int)(row-i)-1,' ');
            for (j=0;j<=i;j++) printf("/ \\ ");
            printf("\n");
            printf("%*c",2*(int)(row-i)-1,'*');
            for (j=0;j<=i;j++) printf("---*");
            printf("\n");
        }
        if (rem){
            printf(" / \\ ");
            j=1;
            while (j<rem){
                printf("/ ");j++;
                if (j>=rem) break;
                printf("\\ ");j++;
            }

            printf("\n*");
            for (j=0;j<(rem+1)/2;j++) printf("---*");
            printf("\n");
        }
	}
	return 0;
}