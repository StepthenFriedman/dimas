#include <stdio.h>

//��ʱ��������ؿ�������Ϊ��.
//���Ʒ�:���������ص�λ��Ϊż�������2,
//���������ص�λ��Ϊ����ʱ��������:
//��λ��Ϊ2^n-1,��ôʹ����һ���������Ը���. 

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
