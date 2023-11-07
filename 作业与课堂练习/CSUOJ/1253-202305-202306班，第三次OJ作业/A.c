#include <stdio.h>
int main(){
	int n,m;
	while (scanf("%d/%d",&n,&m)!=EOF){
		if (n<=0||m>12||m<=0) printf("-1\n");
		else if (((n%4==0&&n%100!=0)||(n%400==0))&&m==2) printf("29\n");
		else if (m==2) printf("28\n");
		else if ((m%2)^(m>7)) printf("31\n");
		else printf("30\n");
	}
	return 0;
}
