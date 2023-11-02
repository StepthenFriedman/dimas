#include <stdio.h>

double Power(double base, int exponent)
{
	double res=1;
    if (exponent>0) while (exponent){
    	res*=base;exponent--;
	}
	else if (exponent<0) {
		base=1./base;
		while (exponent){
    		res*=base;exponent++;
		}
	}
	return res;
}

int main(){
	printf("%lf",Power(1.00000001,999999997));
}
