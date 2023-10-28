#include <stdio.h>

int main(){
	int n,ai,i;
	while (scanf("%d",&n)!=EOF) {
		int sum=0;
		for (i=0;i<n;i++){
			scanf("%d",&ai);
			while (ai>=100){
				ai-=100;sum++;
			}
			while (ai>=50){
				ai-=50;sum++;
			}
			while (ai>=10){
				ai-=10;sum++;
			}
			while (ai>=5){
				ai-=5;sum++;
			}
			while (ai>=2){
				ai-=2;sum++;
			}
			while (ai>=1){
				ai-=1;sum++;
			}
		}
		printf("%d\n",sum);
	}
	return 0;
}
