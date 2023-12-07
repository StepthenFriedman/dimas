#include <stdio.h>

int main(){
	char ipt;
	while (scanf("%c",&ipt)!=EOF) putchar((ipt=='T')?'U':ipt);
}
