#include <stdio.h>

int gcd(int a,int b){
    if(!b) return a;
    return gcd(b,a%b);
}

int main(){
	int a,b,c,d,e,f,res1,res2,g;
	while (scanf("%d %d %d %d",&a,&b,&c,&d)!=EOF){
		res1=f=b*d;res2=e=a*d+c*b;
		g=gcd(e,f);
		printf("%d %d\n",res2/g,res1/g);
	}
	return 0;
}
