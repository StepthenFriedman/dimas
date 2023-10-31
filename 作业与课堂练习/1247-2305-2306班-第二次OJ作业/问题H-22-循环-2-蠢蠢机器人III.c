#include<stdio.h>

int main(){
	long long int n,i,min,min2,num,cost;
	while (scanf("%lld",&n)!=EOF){
		scanf("%lld %lld",&num,&cost);
		min=((n/num)+1)*cost;
		scanf("%lld %lld",&num,&cost);
		min2=((n/num)+1)*cost;min=min<min2?min:min2;
		scanf("%lld %lld",&num,&cost);
		min2=((n/num)+1)*cost;min=min<min2?min:min2;
		printf("%lld\n",min);
	}
	
	return 0;
}
