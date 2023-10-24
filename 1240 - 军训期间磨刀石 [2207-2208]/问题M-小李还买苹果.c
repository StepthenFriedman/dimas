#include <stdio.h>

int main(){
	int n;
	while (scanf("%d",&n)!=EOF){
		if (n%2) printf("No\n");
		else printf("Yes\n");
	}
	return 0;
}
