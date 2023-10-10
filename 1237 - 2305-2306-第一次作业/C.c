#include <stdio.h>
int main(){
	int x=1,y=1;
	while (scanf("%d %d",&x,&y)!=EOF)printf("%d %d\n",x/y,x%y);
	return 0;
}
