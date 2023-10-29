#include <stdio.h>

int main(){
	int a,b;
	while (scanf("%d %d",&a,&b)!=EOF) printf("%d\n",(b-2)?((b>7)^(b%2))?31:30:(a%4)?28:29);
	return 0;
}
