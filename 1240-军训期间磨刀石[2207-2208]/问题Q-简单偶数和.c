#include <stdio.h>

int main(){
	int n,sum,ipt,i;
	while (scanf("%d",&n)!=EOF){
		sum=0;
		for (i=0;i<n;i++) {
			scanf("%d",&ipt);
			sum+=(!(ipt%2))*ipt;
		}
		printf("%d\n",sum);
	}
	return 0;
}
