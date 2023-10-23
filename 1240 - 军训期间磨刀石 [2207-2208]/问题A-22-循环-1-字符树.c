#include <stdio.h>

int main(){
	int n;
	while (scanf("%d",&n)!=EOF){
		for (int i=0;i<n;i++){
			for (int j=0;j<=i;j++) putchar(65+i);
			putchar('\n');
		}
	}
	return 0;
}
