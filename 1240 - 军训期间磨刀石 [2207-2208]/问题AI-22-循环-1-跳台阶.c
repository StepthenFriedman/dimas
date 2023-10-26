#include <stdio.h>
int xCy(int x,int y){
	int res=1;
	for (int i=0;i<y;i++) res*=x-i;
	for (int i=2;i<=y;i++) res/=i;
	return res;
}

int main(){
	int t,n,i;
	while (scanf("%d",&t)!=EOF) {
		int res=1;
		for (i=0;i<t;i++){
			scanf("%d",&n);
			printf("%d\n",xCy(9,3);
		}
	}
	return 0;
}
