#include <stdio.h>

int main(){
	int n,ipt,i;
	float j=0.0,sqt=0.0;
	while (scanf("%d",&n)!=EOF){
		int sum[n];
		for (i=0;i<n;i++){
			sum[i]=1;
			scanf("%d",&ipt);
			if (ipt==1) continue;
			sqt=sqrt(ipt);
			for (j=2.0;j<sqt;j++) {
				int intj=j;
				if (ipt%intj==0) {
					printf("%d ",intj);
					sum[i]+=intj+(ipt/intj);
				}
			}
			if (ipt==sqt*sqt) {
				printf("sqrt ");
				sum[i]+=sqt;
			}
		}
		for (i=0;i<n;i++) printf("sum:%d\n",sum[i]);
	}
	return 0;
}
