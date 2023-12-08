#include <stdio.h>
int main(){
	long long int n,l,r;
    while (~scanf("%lld %lld %lld",&n,&l,&r)){
        int i,j=0;long long int a,b;
        for(i=1;i<=n;i++){
            scanf("%lld %lld",&a,&b);
            if(a<=l&&b>=r) {j=1;}
            else continue;
        }
        if(j==0)j=-1;
        printf("%d\n",j); 
    }
	return 0;
}