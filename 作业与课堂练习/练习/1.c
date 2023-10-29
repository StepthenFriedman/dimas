#include <stdio.h>

int main(){
	float ipt;
	while (scanf("%f",&ipt)!=EOF) printf("%.2f\n",(ipt<=110)?(ipt/2):(ipt<=210)?((ipt-110.)*0.55+55.):((ipt-210)*0.7+110.));
	return 0;
}
