#include <stdio.h>
int main(){
	int n,m;
	while (scanf("%d/%d",&n,&m)!=EOF){
		if (n<=0||m>12||m<=0) {
			printf("-1\n");continue;
		}
		if ((n%4==0&&n%100!=0)||(n%400==0)) {
			if (m==2) {
				printf("29\n");continue;
			}
		}
		if (m==2) {
			printf("28\n");continue;
		}
		if (m==1||m==3||m==5||m==7||m==8||m==10||m==12){
			printf("31\n");continue;
		}
		else printf("30\n");
	}
	return 0;
}
