#include <stdio.h>
int main(){
	int t,a,b;
	while (~scanf("%d",&t)){
        a=0,b=0;
		while (t>=3600) t-=3600,a++;
        while (t>=60) t-=60,b++;
		printf("%d:%d:%d\n",a,b,t);
	}
	return 0;
}