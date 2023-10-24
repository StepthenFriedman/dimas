#include <stdio.h>

int main(){
	int C,i;
	while (scanf("%d",&C)!=EOF){
		int n[C],res[C],a,b,c;
		for (i=0;i<C;i++) {
			scanf("%d",&n[i]);
			a=n[i]/2;n[i]-=a;b=(n[i]*2)/3;c=n[i]-b;
			res[i]=(a/10)+(b/10)+(c/10)+((a%10)>0)+((b%10)>0)+((c%10)>0);
		}
		for (i=0;i<C;i++) printf("%d\n",res[i]);
	}
	return 0;
}
