#include <stdio.h>
int main(){
	char ipt[100000];
	while (gets(ipt)!=NULL){
		for (int i=0;ipt[i]!='\0';i++){
			if (ipt[i]>=97&&ipt[i]<97+26) ipt[i]=97*2+25-ipt[i];
			else if (ipt[i]>=65&&ipt[i]<65+26) ipt[i]=65*2+25-ipt[i];
		}
		printf("%s\n",ipt);
	}
	return 0;
}