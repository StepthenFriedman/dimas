#include <stdio.h>

int main(){
	int n,min1,min2,cards[100000];
	long long int sum;
	int i,times=0,indx1,indx2;
	while (scanf("%d",&n)!=EOF){
		sum=0;
		for (i=0;i<n;i++) scanf("%d",&cards[i]);
		for (times=0;times<n-1;times++){
			indx1=indx2=times;min1=min2=cards[times];
			for (i=times+1;i<n;i++){
				if (min1>cards[i]){
					min2=min1;indx2=indx1;
					min1=cards[i];indx1=i;
				}
			}
			cards[indx2]+=min1;
			sum+=min1+min2;
			cards[indx1]=cards[times];
		}
		printf("%lld\n",sum);
	}
	return 0;
}
