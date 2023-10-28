#include <stdio.h>
int main(){
	int i,j,k;
	while (scanf("%d",&i)!=EOF){
		for (j=0;j<i;j++){
			printf("%*d\n",j+1,j+1);
		}
		putchar('\n');
	}
	return 0;
}
