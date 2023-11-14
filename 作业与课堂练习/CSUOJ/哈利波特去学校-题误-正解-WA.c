#include <stdio.h>

//有时候哈利波特可以以退为进.
//逆推法:当哈利波特的位置为偶数则除以2,
//当哈利波特的位置为奇数时分类讨论:
//若位置为2^n-1,那么使倒退一步反而可以更快. 

int is2n(long long int x){
	if (x==1) return 1;
	do{
		if (x%2) return 0;
		x>>=1;
	}
	while (x>1);
	return 1;
}

int main(){
	long long int K,i,j,x,y,res;
	while (scanf("%lld",&K)!=EOF){
		for (i=0;i<K;i++){
			scanf("%lld",&x);
			res=0;
			while (x){
				if (x%2){
					if (x>15&&is2n(x+1)) x++;
					else x--;
				}else x/=2;
				res++;
			}
			printf("%lld\n",res);
		}
	}
	return 0;
}
