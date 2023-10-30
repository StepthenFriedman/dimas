#include<stdio.h>
int max(int x,int y,int z){
	int res=x;
	res=res>y?res:y;
	res=res>z?res:z;
	return res;
}

int main(){
    int N,V, i,j,k;
	int dp[2][10000],v[100],w[100];
    while(~scanf("%d %d", &N, &V)){
    	int S;
    	for (i=0;i<=N;i++) {
    		dp[0][i]=0;
		}
    	for (i=1;i<=N;i++) {
    		scanf("%d", &S);
    		for (j=0;j<=V;j++) dp[i%2][j]=dp[!(i%2)][j];
    		for (j=0;j<S;j++) {
    			scanf("%d %d", &v[i], &w[i]);
    			for (k=V;k>=v[i];k--){
    				dp[i%2][k]=max(dp[!(i%2)][k-v[i]]+w[i],dp[i%2][k],dp[!(i%2)][k]);
				}
			}
		}
	    printf("%d\n",dp[N%2][V]);
	}
    return 0;
}
