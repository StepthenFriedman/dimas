#include <stdio.h>

int main(){
	int n,ipt,i,j;
	float sqt=0.0;
	while (scanf("%d",&n)!=EOF){
		int sum[n];
		for (i=0;i<n;i++){
			sum[i]=1;
			scanf("%d",&ipt);
			if (ipt==1) continue;
			sqt=sqrt(ipt);
			for (j=2;(float)j<sqt;j++) if (ipt%j==0) sum[i]+=j+(ipt/j);
			if (ipt==(int)sqt*(int)sqt) sum[i]+=sqt;
		}
		for (i=0;i<n;i++) printf("%d\n",sum[i]);
	}
	return 0;
}
