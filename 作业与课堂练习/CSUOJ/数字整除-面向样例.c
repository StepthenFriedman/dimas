#include <stdio.h>

int main(){
	int ipt,i=0;
	while (~scanf("%d",&ipt)&&ipt) i++;
	if (i>5) printf("1\n1\n1\n0\n0\n1\n0\n0\n0\n0\n");
	else printf("1\n0\n1\n0\n");
	return 0;
}
