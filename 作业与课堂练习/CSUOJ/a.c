#include<stdio.h>
int arr(int x){
	int i,sum=0;
	for(i=2;i*i<=x;i++){
		if(x%i==0){
			sum++;
			break;
		}
	}
	if(sum==0)return 1;
	else return 0;
}
int main(){
	long long int i,a,b,j,k;
	while(scanf("%lld",&k)!=EOF){
		for(i=0;i<k;i++){
			long long int sum=0;
			scanf("%lld %lld",&a,&b);
			for(j=a;j<=b;j++) if(arr(j)&&arr(j+2)&&j+2<=b&&j!=1)sum++;
			printf("%lld\n",sum);
		}
	}
	return 0;
}