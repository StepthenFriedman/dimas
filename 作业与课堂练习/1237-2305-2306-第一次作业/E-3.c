#include <stdio.h>

int main(){
	int L,R;
	while (scanf("%d %d",&L,&R)!=EOF){
		int i,x,res=0;
		for (i=L;i<=R;i++) {
			x=i;
			while (x){
				if (x%10==7) res++;
				x/=10;
			}
		}
		printf("%d\n",res);
	}
	return 0;
}
