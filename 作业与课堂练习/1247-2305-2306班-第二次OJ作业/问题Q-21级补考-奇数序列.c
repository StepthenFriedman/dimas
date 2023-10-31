#include<stdio.h>

int main(){
	int n,ni,sum,i=0,j=0,k;
	while (scanf("%d",&n)!=EOF){
		sum=0;
		for (k=0;k<n;k++) {
			scanf("%d",&ni);
			sum+=ni%2;
		}
		if ((n%2)*(sum%2)) printf("YES\n");
		else printf("NO\n");
	}
	
	return 0;
}
