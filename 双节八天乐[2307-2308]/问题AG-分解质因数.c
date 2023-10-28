#include <stdio.h>
int main(){
	int a,b,i,j,x;
	while (scanf("%d %d",&a,&b)!=EOF){
		for (i=a;i<=b;i++) {
			x=i;j=2;printf("%d=",x);
			again:
				if (!(x%j)) {
					if (x==j) printf("%d\n",j);
					else{
						x/=j;
						printf("%d*",j);
						j=2;
						goto again;
					}
				}
				else {
					j++;goto again;
				}
		}
	}
	return 0;
}
