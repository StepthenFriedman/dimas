#include <stdio.h>

int main(){
	float ipt=0.0;
	while (scanf("%f",&ipt)!=EOF){
		int res=ipt+0.5;
		printf("%-8.3f %6d\n",ipt,res);
	}
	return 0;
}
