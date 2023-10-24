#include <stdio.h>

int main(){
	int M1,M2,R1=0,R2=0,R3=0,i;
	while (scanf("%d %d",&M1,&M2)!=EOF){
		char cmd[200];
		scanf("%s",&cmd);
		R1=R2=R3=0;
		for (i=0;cmd[i]!='\0';i++) {
			switch (cmd[i]) {
				case 'A': R1=M1;continue;
				case 'B': R2=M2;continue;
				case 'C': M1=R3;continue;
				case 'D': M2=R3;continue;
				case 'E': R3=R1+R2;continue;
				case 'F': R3=R1-R2;continue;
			}
		}
		printf("%d,%d\n",M1,M2);
	}
	return 0;
}
