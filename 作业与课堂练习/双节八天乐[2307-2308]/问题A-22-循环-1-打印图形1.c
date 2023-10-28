#include <stdio.h>
int main(){
	int ipt,i;
	while (scanf("%d",&ipt)!=EOF){
		for (i=0;i<ipt;i++) putchar('*');
		printf("\n\n");
	}
	return 0;
}
