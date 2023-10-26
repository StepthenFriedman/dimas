#include <stdio.h>

int tenth(int i){
	int res=1;
	while(i){i--;res*=10;}
	return res;
}

int digit(int x,int i){
	return (x/tenth(i))-((x/tenth(i+1))*10);
}

int main(){
	int n=0,i=0,j=0,sevs=0;
	while (scanf("%d",&n)!=EOF){
		sevs=0;
		for (i=1;i<=n;i++) {
			if (i%7==0) sevs++;
			else for (j=0;j<5;j++) if (digit(i,j)==7) {
				sevs++;break;
			}
		}
		printf("%d\n",sevs);
	}
	return 0;
}
