#include <stdio.h>
int main() {
	int m,n,i,a,b,p,q,d;
	scanf("%d",&m);
	for (i=0;i<m;i++) {
		scanf("%d", &n);
		for (a = 1; a <= n - 1; a++)
			putchar('-');
		printf("\n");
		for (b = 0; b < (n - 2) / 2; b++) {
			for (p = b; p > 0; p--)printf(" ");
			putchar('\\');
			if (b != 0) {
				for (q = (((n - 2) / 2) - 1 - b) * 2 + 1; q >= 1; q--)
					putchar('*');
			}
			else {
				for (d = n - 3; d>= 1; d--)
					putchar(' ');
			}
			putchar('/'); printf("\n");
		}
			for (d = (n - 2) / 2; d > 0; d--) {
				for (p = d - 1; p > 0; p--)
					printf(" "); printf("/");
				for (p = (n - 2) / 2 - d; p > 0; p--)
					printf(" "); putchar('*');
				for (p = (n - 2) / 2 - d; p > 0; p--)
					printf(" "); putchar('\\');
				printf("\n");

			}for (a = 1; a <= n - 1; a++)
				putchar('-');



		
	}return 0;
}
