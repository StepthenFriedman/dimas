#include <stdio.h>

int main(){
    int i,j,n;
	while(scanf("%d",&n)!=EOF){
        long long arr[32]={[0 ... 31]=1};
		for (i=1;i<n;i++) for (j=i;j<n;j++) arr[j]+=arr[j-1];
        printf("%lld\n",arr[n-1]);
	}
	return 0;
}