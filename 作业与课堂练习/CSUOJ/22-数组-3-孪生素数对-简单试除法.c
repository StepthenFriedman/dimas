#include <stdio.h>
#include <math.h>
#define LEN 5000000

int pair_prime[LEN+5]={0};
int amount[LEN+5]={0};

int Judge(int n){
	if(n<2) return 0;
	int i,sqt=(int)sqrt(n);
	for(i=2;i<=sqt;i++) if(n%i==0) return 0;
	return 1;
}

int main()
{
	int i;
	pair_prime[1]=pair_prime[2]=0;
	pair_prime[3]=pair_prime[5]=1;
	for(i=6;i<=LEN;i+=6) if(Judge(i-1)&&Judge(i+1)) pair_prime[i-1]=pair_prime[i+1]=1;
	int cnt=0;
	for(i=5;i<=LEN;i++){
		if(pair_prime[i]&&pair_prime[i-2]) amount[i]=++cnt;
		else amount[i]=amount[i-1];
	}
	int K,a,b;
	scanf("%d",&K);
	while(K--){
		scanf("%d%d",&a,&b);
		if(Judge(a-1)&&Judge(a+1)) printf("%d\n",amount[b]-amount[a]-1);
		else printf("%d\n",amount[b]-amount[a]);
	}
	return 0;
}