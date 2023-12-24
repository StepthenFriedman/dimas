#include<stdio.h>
#include<string.h>

int max(int a,int b){
	return a>b?a:b;
} 

int main(){
    int dp[2][1001],i,j,len1,len2;
	char ipt1[1010],ipt2[1010],arr1[1001],arr2[1001];
	while(scanf("%s %s",&ipt1,&ipt2)!=EOF){
		memset(dp,0,sizeof(dp));
        for (i=j=0;ipt1[i]!='\0';i++) if (strchr(ipt2,ipt1[i])!=NULL) arr1[j++]=ipt1[i];
        arr1[j]='\0';
        if (!j) {printf("0\n");continue;}
        for (i=j=0;ipt2[i]!='\0';i++) if (strchr(arr1,ipt2[i])!=NULL) arr2[j++]=ipt2[i];
        arr2[j]='\0';
		len1=strlen(arr1);len2=strlen(arr2);
		for(i=1;i<=len1;i++) for(j=1;j<=len2;j++){
			if(arr1[i-1]==arr2[j-1]) dp[i%2][j]=dp[!(i%2)][j-1]+1;
			else dp[i%2][j]=max(dp[!(i%2)][j],dp[i%2][j-1]);
		}
		printf("%d\n",dp[len1%2][len2]);
	}
	return 0;
}