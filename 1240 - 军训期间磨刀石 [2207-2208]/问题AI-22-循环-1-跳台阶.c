#include <stdio.h>

int main(){
	int t,n,i;
	while (scanf("%d",&t)!=EOF) {
		int res[t],max2;
		for (i=0;i<t;i++){
			scanf("%d",&n);
			res[i]=1<<(n-1);
		}
		for (i=0;i<t;i++) printf("%d\n",res[i]);
	}
	return 0;
}
