#include<stdio.h>

int main(){
	int x,res;
	while (scanf("%d",&x)!=EOF){
		res=0;int ori=x;
		res+=x/38;x=x%38;res+=x/18;x=x%18;res+=x/8;x=x%8;
		if ((ori-x)>68) res++;
		printf("%d\n",res);
	}
	
	return 0;
}
