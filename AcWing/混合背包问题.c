#include<stdio.h>
#define max(x,y) (x)>(y)?(x):(y)
#define min(x,y) ((x)<(y)?(x):(y))
int main(){
    int t,m;
	int dp[2000]={0};
	register int x=1;
	register int i=1,j=t,lim=1;
    while(~scanf("%d %d", &m, &t)){
    	int c,v,s;
    	for(i=1;i<=m;i++){  
    		scanf("%d %d %d",&c,&v,&s);
    		if (s==-1) s=1;
    	    for(j=t;j>=c;j--){
    	    	lim=s==0?j/c:min(s,j/c);
				for (x=1;x<=lim;x++){
					dp[j] = max(dp[j],dp[j-c*x]+v*x);
				}
    	    }
	    }
	    printf("%d\n",dp[t]);
	}
    return 0;
}
