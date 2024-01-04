#include <stdio.h>
#include <string.h>
int main(){
	char ipt[1000];int i;
	while (1){
		gets(ipt);
		if (!strcmp("ENDOFINPUT",ipt)) return 0;
		gets(ipt);
		for (i=0;ipt[i]!='\0';i++){
			if (ipt[i]<='Z'&&ipt[i]>='A'){
				ipt[i]-=5;if (ipt[i]<'A') ipt[i]+=26;
			}
			else if (ipt[i]<='z'&&ipt[i]>='a'){
				ipt[i]-=5;if (ipt[i]<'a') ipt[i]+=26;
			}
		}
		printf("%s\n",ipt);
		gets(ipt);
	}
	return 0;
}
