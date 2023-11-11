#include <stdio.h>

typedef struct ListNode{
	int value;struct ListNode* next;
} ln;

int main(){
	int n;
	int i,times=0;
	while (scanf("%d",&n)!=EOF){
		int cards[n],mid=0;
		long long int sum=0;
		for (times=0;times<n;times++) {
			scanf("%d",&mid);
			i=times;
			while (i>0&mid<cards[i-1]){
				cards[i]=cards[i-1];i--;
			}
			cards[i]=mid;
		}
		for (times=0;times<n-1;times++){
			i=times+1;
			cards[i]+=cards[times];
			mid=cards[i];
			sum+=mid;
			while (mid>cards[i+1]&i<n-1){
				cards[i]=cards[i+1];i++;
			}
			cards[i]=mid;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
