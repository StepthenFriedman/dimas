#include <stdio.h>
int main(){
	int a,b,c,max;
	while (scanf("%d %d %d",&a,&b,&c)!=EOF){
		max=a+(b*c);
		max=max>(a*b)+c?max:(a*b)+c;
		max=max>(a+b)*c?max:(a+b)*c;
		max=max>a*(b+c)?max:a*(b+c);
		max=max>a+b+c?max:a+b+c;
		max=max>a*b*c?max:a*b*c;
		printf("%d\n",max);
	}
	return 0;
}
