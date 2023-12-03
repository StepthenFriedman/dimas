/*
题目描述
小南最近喜欢上了魔方，设计了一个平面魔方。平面魔方是一个n×n(2≤n≤ 10)的矩阵，最开始用数据1~n2填充。魔方的操作指令集如下：
（1）指令1：“L x y”表示矩阵的第x行循环左移y次；
（2）指令2：“R x y”表示矩阵的第x行循环右移y次；
（3）指令3：“U x y”表示矩阵的第x列循环上移y次；
（4）指令4：“D x y”表示矩阵的第x列循环下移y次；
其中矩阵的行号和列号x从1开始编号，满足1≤x≤n；移动次数y满足1≤y≤n−1。
说明：5个数据a1,a2,a3,a4,a5循环左移1次会变成a2,a3,a4,a5,a1。
要求：对给定的初始魔方，经过若干次操作后形成新的魔方，按行将新魔方的所有数字输出在一行上，数字之间用一个空格分开，行首和行末无空格。
输入
多个样例。每个样例输入包含1+m行：
第1行输入两个整数n(2≤n≤10)和m(1≤m≤100)，分别表示矩阵的大小和指令的条数。
接下来的m行是m条指令，输入格式为“C x y”，字母C(L或R或U或D)代表移动的方向，整数x(1≤x≤n)代表移动的行或列号，y(1≤y≤n−1)代表移动次数。
输出
对于每个样例，按行输出新魔方的所有数字。每个样例结果输出占一行。
*/

#include <stdio.h>

int main(){
    int n,m,i,j,k,cmdx,cmdy,temp;char cmd;
	while (~scanf("%d%d",&n,&m)){
        int cube[n][n];
        for (i=0;i<n;i++) for (j=0;j<n;j++) cube[i][j]=i*n+j+1;
        for (i=0;i<m;i++){
            getchar();
            scanf("%c%d%d",&cmd,&cmdx,&cmdy);
            if (cmd=='L') for (k=0;k<cmdy;k++){
                temp=cube[cmdx-1][0];
                for (j=0;j<n-1;j++) cube[cmdx-1][j]=cube[cmdx-1][j+1];
                cube[cmdx-1][n-1]=temp;
            }
            else if (cmd=='R') for (k=0;k<cmdy;k++){
                temp=cube[cmdx-1][n-1];
                for (j=n-1;j>0;j--) cube[cmdx-1][j]=cube[cmdx-1][j-1];
                cube[cmdx-1][0]=temp;
            }
            else if (cmd=='D') for (k=0;k<cmdy;k++){
                temp=cube[n-1][cmdx-1];
                for (j=n-1;j>0;j--) cube[j][cmdx-1]=cube[j-1][cmdx-1];
                cube[0][cmdx-1]=temp;
            }
            else if (cmd=='U') for (k=0;k<cmdy;k++){
                temp=cube[0][cmdx-1];
                for (j=0;j<n-1;j++) cube[j][cmdx-1]=cube[j+1][cmdx-1];
                cube[n-1][cmdx-1]=temp;
            }

        }
        for (i=0;i<n;i++) for (j=0;j<n;j++) printf("%d ",cube[i][j]);
        putchar('\n');
    }
	return 0;
}