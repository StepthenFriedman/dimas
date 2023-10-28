#include <stdio.h>
int main(){
	int ipt,i,j;
	while (scanf("%d",&ipt)!=EOF){
		for (i=0;i<ipt;i++) {
			for (j=0;j<=i;j++) putchar(65+i);
			putchar('\n');
		}
	}
	return 0;
}
