#include <stdio.h>
int main(){
	int i,j,k;
	while (scanf("%d",&i)!=EOF){
		for (j=0;j<i;j++){
			for (k=1;k<j;k++) putchar(' ');
			printf(65+k);
		}
	}
	return 0;
}
