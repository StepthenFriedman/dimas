#include <stdio.h>

int main(){
	int t,n,i,j,k,sandlen;
	scanf("%d",&t);
	for (i=0;i<t;i++){
		scanf("%d",&n);
		for (j=0;j<n-1;j++) putchar('-');putchar('\n');
		sandlen=n-3;
		for (j=0;j<n/2-1;j++) {
			printf("%*c",j+1,'\\');
			if (j) for (k=0;k<sandlen;k++) putchar('*');
			else for (k=0;k<sandlen;k++) putchar(' ');
			printf("/\n");
			sandlen-=2;
		}
		sandlen=1;
		for (j=n/2-1;j>0;j--) {
			printf("%*c",j,'/');
			printf("%*c",sandlen,'*');
			for (k=0;k<sandlen-1;k++) putchar(' ');
			printf("\\\n");
			sandlen++;
		}
		
		for (j=0;j<n-1;j++) putchar('-');printf("\n\n");
	}
	return 0;
}
