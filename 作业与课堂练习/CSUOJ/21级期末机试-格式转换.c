#include<stdio.h>

int main(){
	int hour,min,day,month,year;
	while (scanf("%d:%d,%d/%d/%d",&hour,&min,&month,&day,&year)!=EOF){
		int h=0;
		printf("%d%02d%02d,",year,month,day);
		if (hour>=12) {hour-=12;h=1;}
		printf("%02d:%02d%s\n",hour,min,h?"PM":"AM");
	}
	return 0;
}
