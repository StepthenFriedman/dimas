#include <stdio.h>

int main(){
	char ipt[5];int i,mid,n[4];
	while (scanf("%s",&ipt)!=EOF){
		for (i=0;i<4;i++){
			n[i]=(ipt[i]-39)%10;
		}
		mid=n[0];n[0]=n[2];n[2]=mid;
		mid=n[1];n[1]=n[3];n[3]=mid;
		
		printf("The encrypted number is ");
		int head=0;
		for (i=0;i<4;i++) {
			if (n[i]) head=1;
			if (head) printf("%d",n[i]);
		}
		if (!head) putchar('0');
		putchar('\n');
	}
	return 0;
}
