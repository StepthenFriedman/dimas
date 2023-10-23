#include <stdio.h>

int main(){
	int n=0,i=0;
	while (scanf("%d",&n)!=EOF){
		int m[n];
		for (i=0;i<n;i++) scanf("%d",&m[i]);
		for (i=0;i<n;i++) if (m[i]) {
			putchar('5');
			for (int j=0;j<m[i]-1;j++) putchar('0');
			putchar('5');
			for (int j=0;j<m[i]-1;j++) putchar('0');
			putchar('\n');
		}
		else printf("1\n");
	}
	return 0;
}
