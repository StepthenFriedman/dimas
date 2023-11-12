#include <stdio.h>

int main(){
	int a[6]={1,2,3,4,5,6},i;
	for (i=0;i<6;i++){
		printf(",%d"+!i,a[i]);//the first ',' was removed
	}
	return 0;
}
