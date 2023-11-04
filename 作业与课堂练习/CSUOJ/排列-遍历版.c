#include <stdio.h>

int match(int* a,int *temp,int x){
	for (int i=0;i<4;i++){
		temp[i]=x%10;x/=10;
	}
	for (int i=0;i<4;i++){
		for (int j=0;j<4;j++){
			if (a[i]==temp[j]){
				temp[j]=-1;goto x;
			}
		}
		return 0;
		x:i=i;
	}
	return 1;
}


int main(){
	int a[4]={1,2,3,4},temp[4],i,last=0,max,min;
	while (scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3])!=EOF){
		last=0;
		for (i=1000;i<10000;i++){
			if (match(a,temp,i)){
				if (i/1000!=last/1000&&last) putchar('\n');
				printf("%d ",i);
				last=i;
			}
		}
		putchar('\n');
	}
	return 0;
}
