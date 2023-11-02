#include <stdio.h>

int main(){
	char ipt[200];int i,len,words;
	while (gets(ipt)!=NULL){
		len=0;words=1;
		for (i=0;ipt[i]!='\0';i++){
			if (ipt[i]==' '){
				words++;
			}
		}
		char pf[3*words+1];
		len=i;
		printf("%s\n",ipt);
	}
	return 0;
}
