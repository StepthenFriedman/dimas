#include <stdio.h>

int main(){
	int m=0,n=0,k=0;
	while (scanf("%d",&n)!=EOF){
		k=0;
		for (int i=0;i<n;i++){
			scanf("%d",&m);
			if (m<60) k++;
		}
		printf("%d\n",k*200);
	}
	return 0;
}
