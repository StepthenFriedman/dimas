#include <stdio.h>

int main(){
	long long int K,i,x,res;
	while (scanf("%lld",&K)!=EOF){
		for (i=0;i<K;i++){
			scanf("%lld",&x);
			res=0;
			while (x){
				if (x%2) x--;
				else x/=2;
				res++;
			}
			printf("%lld\n",res);
		}
	}
	return 0;
}
