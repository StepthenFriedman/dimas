#include <stdio.h>

int main(){
	int n,ai,i;
	while (scanf("%d",&n)!=EOF){
		for (i=0;i<n;i++) scanf("%d",&ai);
		if (n>1) printf("NO\n");
		else if (ai%2) printf("NO\n");
		else printf("YES\n");
	}
	return 0;
}
