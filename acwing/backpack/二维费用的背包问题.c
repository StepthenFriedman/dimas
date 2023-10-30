#include<stdio.h>
int max(int x,int y) {
	return x>y?x:y;
}
int main(){
	int N,V,M;
    register int i,j,k;
    while(~scanf("%d %d %d", &N, &V, &M)){
    	int v,m,w,dp[V+1][M+1];
    	for (i=0;i<=V;i++) for (j=0;j<=M;j++) dp[i][j]=0;
    	for(i=1;i<=N;i++){
    		scanf("%d %d %d",&v,&m,&w);
    		for (j=V;j>=v;j--) for (k=M;k>=m;k--){
    	        dp[j][k] = max(dp[j][k],dp[j-v][k-m]+w);
    	    }
    	}
    	printf("%d\n",dp[V][M]);
	}
	return 0;
}
