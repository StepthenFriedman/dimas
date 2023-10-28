#include <stdio.h>

int main(){
	int a,b,c,correct=0;char c1,c2,ipt[5];
	while (scanf("%d%c%d%c%s",&a,&c1,&b,&c2,&ipt)!=EOF){
		if (ipt[0]=='?') continue;
		sscanf(ipt,"%d",&c);
		if ((c1=='+')&(a+b==c)) correct++;
		if ((c1=='-')&(a-b==c)) correct++;
	}
	printf("%d\n",correct);
	return 0;
}
