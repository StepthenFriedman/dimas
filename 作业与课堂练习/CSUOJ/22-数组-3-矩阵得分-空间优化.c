#include <stdio.h>
#include <string.h>

long long max(long long x,long long y){
    return x>y?x:y;
}
long long res[510];

int main(){
    long long n,m,i,j,tmp;
    while (~scanf("%lld%lld",&n,&m)){
		memset(res,0,510*8);
        for (i=0;i<n;i++) {
			for (j=0;j<m;j++) {
				scanf("%lld",&tmp);
				if (!i&&!j) res[j]=tmp;
				else if (!i&&j) res[j]=res[j-1]+tmp;
				else if (!j&&i) res[j]+=tmp;
				else res[j]=max(res[j],res[j-1])+tmp;
				printf("%lld ",res[j]);
			}
			putchar('\n');
		}
    }
}
