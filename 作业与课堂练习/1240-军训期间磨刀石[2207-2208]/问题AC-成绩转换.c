#include <stdio.h>
int main(){
	int ipt;
	while (scanf("%d",&ipt)!=EOF) printf((ipt>100|ipt<0)?"Score is error!\n":"%c\n",(ipt>=90)?'A':(ipt>=80)?'B':(ipt>=70)?'C':(ipt>=60)?'D':'E');
	return 0;
}
