#include <stdio.h>

//逆序输出字符串

int main(){
	char ipt[100000];int i;
	while (gets(ipt)!=NULL){
		for (i=0;ipt[i]!='\0';i++);
        for (i--;i>-1;i--) putchar(ipt[i]);
		printf("\n");
	}
	return 0;
}