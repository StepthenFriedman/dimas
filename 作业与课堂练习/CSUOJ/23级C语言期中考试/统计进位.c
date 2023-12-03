/*
题目描述
老师发现很多学生在进行加法的时候，发现“进位”特别容易出错。于是交给小南一个任务，就是统计两个整数x和y在相加时需要多少次进位，其中x和y满足0≤x,y≤ 109，你能帮他完成任务吗？
输入
多个样例。 每个样例输入1行，包括2个整数x和y(0≤x,y≤ 109)。
输出

每个样例输出一个整数，代表所需要的进位数。每个样例输出结果占一行。
*/

#include <stdio.h>

int digit(long long x,int i){
    while (i) i--,x/=10;
    return x%10;
}

int maxlen(long long x,long long y){
    long long m=x>y?x:y;
    int res=1;
    while (m) m/=10,res++;
    return res;
}

int main(){
    long long x,y;
    int i,j;
	while (~scanf("%lld%lld",&x,&y)){
        int ml=maxlen(x, y),temp=0,res=0;
        for (i=0;i<ml;i++){
            if (digit(x,i)+digit(y,i)+temp>9) res++,temp=1;
            else temp=0;
        }
        printf("%d\n",res);
    }
	return 0;
}