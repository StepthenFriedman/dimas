#include<stdio.h>
#define max(x,y) (x)>(y)?(x):(y)
int main(){
    int t,m;//tΪ������,mΪ��Ʒ����,cΪ��Ʒ���,jΪʣ������,xΪ������Ʒ��Ŀ,vΪ��Ʒ��ֵ 
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
