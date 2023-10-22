#include <stdio.h>

//monotonic sequence optimized,however still TLE 

int smaller(int x,int y){
	if (y==-1) return 0;
	if (x==-1) return 1;
	return (x>y);
}
int main(){
	long int n,min1=-1,min2=-1;
	int i,j,times=0,indx=0,indx2=0;
	while (scanf("%ld",&n)!=EOF){
		int cards[n],mid=0;
		long int sum=0;
		for (i=0;i<n;i++) scanf("%d",&cards[i]);
		i=0;
		while (i<n-1){
			if (cards[i]>cards[i+1]){
				mid=cards[i];
				cards[i]=cards[i+1];
				cards[i+1]=mid;
				if (i) i--;
			}else i++;
		}
		
		while (times<n-1){
			cards[times+1]+=cards[times];
			sum+=cards[times+1];
			i=times+2;
			while (cards[i]<cards[times+1]){
				if (i==n) break;
				else i++;
			}
			i--;
			
			mid=cards[times+1];
			for (j=times+1;j<i;j++){
				cards[j]=cards[j+1];
			}
			cards[i]=mid;
			times++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
