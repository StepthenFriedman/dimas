#include <stdio.h>
int main(){
	int n,i,j,res;
	while (scanf("%d",&n)!=EOF){
		for (i=(int)sqrt((double)n*2.);i*i+i<=2*n;i++);
		i--;res=i*(i+1)*(2*i+1)/6;
		for (j=(i*i+i)/2;j<n;j++) res+=i+1;
		printf("%d\n",res);
	}
	return 0;
}
