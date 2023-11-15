#include <stdio.h>

int main(){
	char ipt[1000];
	int n,i,dirc;
	while (~scanf("%d",&n)){
		scanf("%s",&ipt);
		dirc=n*4;
		for (i=0;i<n;i++){
			if (ipt[i]=='L') dirc--;
			else dirc++;
		}
		switch (dirc%4){
			case 0:printf("N\n");continue;
			case 1:printf("E\n");continue;
			case 2:printf("S\n");continue;
			case 3:printf("W\n");continue;
		}
	}
}
