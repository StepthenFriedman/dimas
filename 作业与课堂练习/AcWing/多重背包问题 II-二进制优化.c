#include<stdio.h>
#define max(x,y) ((x)>(y)?(x):(y))

int main(){
    int t,m,i,j=0,cost,value,k=0,c,v;//t:×ÜÈÝÁ¿
    unsigned int s=0;
	int dp[2000]={0};
    while(~scanf("%d %d", &m, &t)){
    	int n=1;
    	for(i=1;i<=m;i++){
    		scanf("%d %d %d",&cost,&value,&s);
    		int s2=s>>1;j=0;
    		while (s2){
    			c=(1<<j)*cost;v=(1<<j)*value;
				for(k=t;k>=c;k--){
    	            dp[k] = max(dp[k],dp[k-c]+v);
    	        }
				j++;
				s2>>=1;
			}
			for(k=t;k>=((1<<j)*cost);k--){
				c=(s-(1<<j)+1)*cost;v=(s-(1<<j)+1)*value;
    	        dp[k] = max(dp[k],dp[k-c]+v);
    	    }
    	    for (j=0;j<=t;j++) printf("%d ",dp[j]);
    	}
	    printf("%d\n",dp[t]);
	}
    return 0;
}
