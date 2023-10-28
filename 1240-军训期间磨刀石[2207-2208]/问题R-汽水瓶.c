#include <stdio.h>

int main(){
	int res[11],i,j;
	for (i=0;i<11;i++){
		scanf("%d",&res[i]);
		if (!res[i]) break;
		res[i]/=2;
	}
	for (j=0;j<i;j++) printf("%d\n",res[j]);
	return 0;
}
