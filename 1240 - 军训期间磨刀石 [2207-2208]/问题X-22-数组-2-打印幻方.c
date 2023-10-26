#include <stdio.h>

int main(){
	int ipt[1000],n,times=0,i,j,k,digit;
	while (1){
		scanf("%d",&ipt[times]);
		if (ipt[times]==0) break;
		else times++;
	}
	for (i=0;i<times;i++){
		n=ipt[i];
		int map[n][n];
		for (j=0;j<n;j++) for (k=0;k<n;k++) map[j][k]=0;
		
		digit=(n>9?3:(n>3?2:1));
		char pf[]={'%',digit+48,'d',' ','\0'};
		
		k=((n+1)/2)-1;j=n-1;
		
		for (int num=1;num<=n*n;num++){
			map[j][k]=num;
			
			if (j==n-1&k==n-1) j--;
			else if (j==n-1){j=0;k++;}
			else if (k==n-1){k=0;j++;}
			else if (map[j+1][k+1]!=0) j--;
			else {j++;k++;}
		}
		
		for (j=0;j<n;j++){
			for (k=0;k<n;k++) {
				printf(pf,map[j][k]);
			}
			printf("\n");
		} 
		
		printf("\n");
	}
	return 0;
}
