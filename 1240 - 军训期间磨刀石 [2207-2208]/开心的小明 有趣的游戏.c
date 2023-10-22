#include <stdio.h>

//ÎÞÓÅ»¯,TLE

int smaller(int x,int y){
	if (y==-1) return 0;
	if (x==-1) return 1;
	return (x>y);
}
int main(){
	long int n,min1=-1,min2=-1;
	int i,times=0,indx=0,indx2=0;
	while (scanf("%ld",&n)!=EOF){
		int cards[n];
		long int sum=0;
		for (i=0;i<n;i++) scanf("%d",&cards[i]);
		
		while (times<n-1){
			indx=indx2=0;min1=min2=-1;
			for (i=0;i<n;i++){
				if (smaller(min1,cards[i])){
					min2=min1;indx2=indx;
					min1=cards[i];indx=i;
				}
			}
			cards[indx2]+=min1;
			sum+=min1+min2;cards[indx]=-1;
			times++;
		}
		printf("%d\n",sum);
	}
	return 0;
}
