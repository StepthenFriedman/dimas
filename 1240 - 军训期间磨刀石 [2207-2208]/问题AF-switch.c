#include <stdio.h>
#include<math.h>

int main(){
	float x,a;
	while (scanf("%f",&x)!=EOF) printf((x<0.|x>=30.)?"Not define\n":"%.5f\n",(x<10.)?cos(x+3.):(x<20.)?(a=cos(x+7.5))*a:(a=cos(x+4.0))*a*a*a);
	return 0;
}
