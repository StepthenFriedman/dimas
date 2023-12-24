#include <stdio.h>

int main(){
	char str[50];
	int num[50],max,min,len,i,j,k,l;
	while(scanf("%d%d%d%s",&min,&max,&len,&str)!=EOF){
		for(i=0;i<len;i++) num[i]=str[i]-'a'+1;
		 
		for(j=5;j>=1;j--){
			num[len-1]++;
			
			if(num[len-1]>max){
				num[len-2]++;
				for(int j=len-2;j>=1;j--) if(num[j]>max-(len-1-j)) num[j-1]++;
				for(k=1;k<len;k++) if(num[k]>max-(len-1-k)) num[k]=num[k-1]+1;
			}
		
			if(num[0]>max-(len-1)) break;
			for(k=0;k<len;k++) (str[k]=num[k]-1+'a'),printf("%c",str[k]);
			putchar('\n');
		}
	}
	return 0;
}