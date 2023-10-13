#include <stdio.h>

//time complexity:O(y-x)

int sevens(int x){
	char str[5];
	sprintf(str, "%d", x);
	int i=0,r=0;
	for (i=0;i<=5;i++) if (str[i]=='7') r++;
	return r;
}

int main(){
	int x,y;
	while (scanf("%d %d",&x,&y)!=EOF){
		int i=x,r=0;
		for (i=x;i<=y;i++) r+=sevens(i);
		printf("%d\n",r);
	}
	return 0;
}
