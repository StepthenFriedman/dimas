#include <stdio.h>
int main(){
	int ipt;
	while (scanf("%d",&ipt)!=EOF)printf("%c\n",(ipt>=91)?'A':(ipt>=81)?'B':(ipt>=71)?'C':(ipt>=60)?'D':'F');
	return 0;
}
