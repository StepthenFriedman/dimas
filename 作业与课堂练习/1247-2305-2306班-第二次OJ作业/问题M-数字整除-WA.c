#include<stdio.h>

int main()
{
    unsigned long int n,a,b;
    while(1){
    	scanf("%lu",&n);
    	if (!n) break;
    	while (1){
    		a=n/10;b=n%10;
    		if (a>5*b) n=a-5*b;
    		else {
    			printf("%d\n",!(n%17)); break;
			}
		}
    }
    return 0;
}
