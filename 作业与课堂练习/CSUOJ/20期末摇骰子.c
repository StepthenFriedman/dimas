#include <stdio.h>
int main()
{
	int n,i;
	while(scanf("%d",&n)!=EOF){
		char s[8];
		int m,j,h,k;
		for(i=0;i<n;i++){
			int num[7]={0};
			scanf("%s%d",&s,&m);
			for(h=0;h<6;h++){
				num[s[h]-'0']++;
			}
			for(j=0;j<m;j++){
				scanf("%d %d",&n,&k);
				if(k!=1){
					if(num[k]+num[1]>=n){printf("%d:true\n",j+1);}
			    	else{printf("%d:false\n",j+1);}
				}
				else{
					if(num[1]>=n){printf("%d:true\n",j+1);}
				    else{printf("%d:false\n",j+1);}
				}
			}
			printf("\n");
		}
	}
	return 0;
}
