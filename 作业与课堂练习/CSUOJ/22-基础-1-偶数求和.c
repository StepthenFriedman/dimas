#include <stdio.h>

int main(){
	int n,m,i,j;
	while (~scanf("%d%d",&n,&m)){
		for (i=1+m,j=0;j<(n/m);j++,i+=2*m) printf("%d ",i);
		if (n%m) printf("%d\n",((n/m)*m)+1+n);
		else putchar('\n');
	}
	return 0;
}
