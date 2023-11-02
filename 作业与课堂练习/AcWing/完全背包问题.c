#include<stdio.h>
#define max(x,y) (x)>(y)?(x):(y)
int main(){
    int t,m;//t为总容量,m为物品总数,c为物品体积,j为剩余容量,x为单个物品数目,v为物品价值 
	int dp[2000]={0};
	register int i=1,j=t;
    while(~scanf("%d %d", &m, &t)){
    	int c,v;
    	for(i=1;i<=m;i++){  
    		scanf("%d %d",&c,&v);
    	    for(j=c;j<=t;j++){
				dp[j] = max(dp[j],dp[j-c]+v);
    	    }
	    }
	    printf("%d",dp[t]);
	}
    return 0;
}
