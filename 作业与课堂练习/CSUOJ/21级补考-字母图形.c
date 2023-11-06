#include <stdio.h>

int abs(int x){return x>0?x:-x;} 

int main(){
	int n,i,j;
	while (scanf("%d",&n)!=EOF){
		for (i=0;i<n;i++){
			printf("%*s",n-i-1,"");
			for (j=i;j>=-i;j--) putchar(97+abs(j));
			putchar('\n');
		}
	}
	return 0;
}
