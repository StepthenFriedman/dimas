#include<stdio.h>
int main(){
    int N,V;
    int i,j,k,b,x;
    int v,w,s,head=0,tail=1;
    while(~scanf("%d %d", &N, &V)){
    	int queue[V+1],dp[2][V+1];
		for (i=0;i<=V;i++) dp[0][i]=0;
    	for(i=1;i<=N;i++){
    		b=i%2;
    		scanf("%d %d %d",&v,&w,&s);
    		for (j=0;j<v;j++){
    			head=0,tail=1,queue[0]=0;
    			for (k=0;(k*v+j)<=V;k++){
    				if (k-queue[head]>s) head++;
    				x=dp[!b][k*v+j];
    				while (dp[!b][queue[tail-1]*v+j]+w*(k-queue[tail-1])<x & tail>head) {
						tail--;
					}
    				queue[tail]=k;tail++;
					dp[b][k*v+j]=dp[!b][queue[head]*v+j]+w*(k-queue[head]);
				}
			}
			
	    }
	    printf("%d\n",dp[i%2][V]);
  	}
    return 0;
}
