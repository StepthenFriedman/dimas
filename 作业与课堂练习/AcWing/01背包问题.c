#include<stdio.h>
#define max(x,y) x>y?x:y

int main(){
    long int t,m;
	int dp[2000]={0};
    while(~scanf("%d %d", &m, &t)){
    	int c,v;
    	for(int i=1;i<=m;i++){
    		scanf("%d %d",&c,&v);
    	    for(int j=t;j>=c;j--){
    	        dp[j] = max(dp[j],dp[j-c]+v);
    	    }
	    }
	    printf("%d",dp[t]);
	}
    return 0;
}
