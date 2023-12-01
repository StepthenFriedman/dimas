#include<stdio.h>
int main()
{
	long long a[2],x,i;
	while(scanf("%lld",&x)!=EOF){
		if (x==1) printf("1\n");
		else if (x==2) printf("2\n");
		else {
			a[0]=1;a[1]=2;
			for(i=2;a[!(i%2)]<x;i++){
				a[i%2]=a[i%2]+a[!(i%2)];
			}
			if (a[!(i%2)]==x) printf("%lld\n",i);
			else printf("0\n");
		}
	}
	return 0;
}

