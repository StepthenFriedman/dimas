#include <stdio.h>

//time complexity:O(log(y))

int tenth(int i){
	int res=1;
	while(i){i--;res*=10;}
	return res;
}

int digit(int x,int i){
	if (i==-1) return 0;
	else return (x/tenth(i))-((x/tenth(i+1))*10);
}

int main(){
	int x=0,y=0,i=0,sevs=0;
	while (scanf("%d %d",&x,&y)!=EOF){
		sevs=0;
		for (i=0;i<5;i++) sevs+=((y/tenth(i+1))-(x/tenth(i+1))+(digit(y,i)>7)+(digit(x,i)<=7)-1)*tenth(i)+(digit(y,i)==7)*((y%tenth(i))+1)-(digit(x,i)==7)*(x%tenth(i));
		printf("%d\n",sevs);
	}
	return 0;
}
