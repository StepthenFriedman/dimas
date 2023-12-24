#include<stdio.h>
#include<string.h>

int max(int a,int b){
	int y=(a>b)?a:b;
	return y;
} 

int main(){
    int lena,lenb;
    int dp[1001][1001];
	char a[1001],b[1001];
	while(scanf("%s %s",&a,&b)!=EOF){
		memset(dp,0,sizeof(dp));
		lena=strlen(a);lenb=strlen(b);
		for(int i=1;i<=lena;i++){
			for(int j=1;j<=lenb;j++){
				if(a[i-1]==b[j-1]){
					dp[i][j]=dp[i-1][j-1]+1;
				}
				else{
					dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
				}
			}
		}
		printf("%d\n",dp[lena][lenb]);
	}
	return 0;
}