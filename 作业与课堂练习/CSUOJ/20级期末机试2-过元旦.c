#include<stdio.h>
#include<string.h>

int day[]={0,31,28,31,30,31,30,31,31,30,31,30,31};

int main()
{
    int T,y,m,d,res,i;
    scanf("%d", &T);
	while(T--){
        res=0;
        scanf("%d-%d-%d",&y,&m,&d);
        if (y==2021) {printf("1\n");continue;}
        for (i=y+1;i<2021;i++){
            if ((i%4==0&&i%100!=0)||i%400==0){
                res+=366;
            }else res+=365;
        }
        for (i=m+1;i<13;i++){
            res+=day[i];
        }
        res+=day[m]-d;
        if (m<3&&((y%4==0&&y%100!=0)||y%400==0)) res++;
        printf("%d\n",res+2);
	}
	return 0;
}
