#include <stdio.h>  
int s[1000000]={0};
int main(){
	int n,i,j,k,a,b,m;
	while(~scanf("%d",&n)){
		int sum=0;
		for(i=0;i<n;i++){
			scanf("%d",&a);
			sum+=a;
			s[i]=sum;
		}
		scanf("%d",&m);
		for(j=1;j<=m;j++){
			scanf("%d",&b);
			for(k=0;k<n;k++){
				if(b<=s[k]){printf("%d\n",k+1); break;}
			}
		}
	}
	return 0;
}
