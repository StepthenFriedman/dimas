#include <stdio.h>

int isGoodYear(int i){
    return (i%4==0&&i%100!=0)||i%400==0;
}

int day[13]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main(){
    int y,m,d,sum,i;
	while (sum=0,~scanf("%d%d%d",&y,&m,&d)){
        if (isGoodYear(y)) day[2]=29;
        else day[2]=28;
        for (i=1;i<m;i++) sum+=day[i];
        sum+=d;
        printf("%d\n",sum);
    }
	return 0;
}
