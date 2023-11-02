#include <stdio.h>

int main(){
	int n,i,j,k;
	while (scanf("%d",&n)!=EOF){
		k=n;
		for (i=0;i<n;i++){
			for (j=1;j<k;j++) putchar(' ');
			for (j=i;j>0;j--) putchar(97+j);
			for (j=0;j<=i;j++) putchar(97+j);
			putchar('\n');k--;
		}
	}
	return 0;
}
