#include <stdio.h>
int main(){
	float ipt;
	while (scanf("%f",&ipt)!=EOF){
		printf("%-8.3f %6.0f\n",ipt,ipt);
	}
	return 0;
}
