#include <stdio.h>

double Power(double base, int exponent)
{
	double res=1,newbase=base,next;int t=1;
    if (!exponent) return res;
	else if (exponent<0) {
		newbase=1./base;exponent=-exponent;
	}
	x:next=newbase;t=1;
    while (t<(exponent>>1)){
    	next*=next;t<<=1;
	}
	exponent-=t;res*=next;
	if (exponent>8) goto x;
	t=0;
    while (t<exponent){
    	res*=newbase;t++;
	}
	return res;
}

int main(){
	printf("%lf",Power(-2,-4));
}
