#include <stdio.h>

int main(){
	int n=0,i,j,indx,max;
	while (scanf("%d",&n)!=EOF){
		int ipt,num[n],times[n],head=0,IsRept=0;
		for (i=0;i<n;i++) {
			scanf("%d",&ipt);
			IsRept=0;
			for (j=0;j<head;j++){
				if (num[j]==ipt) {
					IsRept=1;times[j]++;break;
				}
			}
			if (!IsRept){
				num[head]=ipt;times[head]=1;
				head++;
			}
			max=indx=0;
			for (j=0;j<head;j++){
				if (max<times[j]){
					indx=j;max=times[j];
				}
				else if ((max==times[j])&(num[indx]>num[j])){
					indx=j;
				}
			}
		}
		printf("%d\n%d\n",num[indx],times[indx]);
	}
	return 0;
}
