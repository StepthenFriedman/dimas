#include <stdio.h>

int main(){
	char ipt[1000];int i;
	while (gets(ipt)!=NULL){
		for (i=0;ipt[i]!='\0';i++){
			if (ipt[i]<91&ipt[i]>64){
				ipt[i]-=5;if (ipt[i]<65) ipt[i]+=26;
			}
		}
		printf("%s\n",ipt);
	}
	return 0;
}
