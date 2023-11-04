#include <stdio.h>
int main(){
	char ipt[1000];
	while (gets(ipt)!=NULL){
		printf("%s\n",ipt);
	}
	return 0;
}
