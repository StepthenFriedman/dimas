#include <stdio.h>
int main(){
	int n,i,x;
	while (scanf("%d",&n)!=EOF){
		int arr[n];
		for (i=0;i<n;i++) scanf("%d",&arr[i]);
		scanf("%d",&x);
		for (i=0;i<n;i++) if (arr[i]==x) {
			printf("%d\n",i+1);goto end;
		}
		printf("-1\n");
		end:i++;
	}
	return 0;
}
