#include <stdio.h>

int a(int x,int times){
	int res=x;
	for (int i=0;i<times;i++) res=res*2-1;
	return res;
}

int main(){
	int n,i,times,start;
	while (scanf("%d",&n)!=EOF){
		times=0;start=1;
		while (n>2){
			for (i=2;i<=n;i+=2) printf("%d ",a(i,times));times++;
			n=(n+1)/2;
		}
		printf("\n%d %d\n",1,a(2,times));
	}
	return 0;
}
