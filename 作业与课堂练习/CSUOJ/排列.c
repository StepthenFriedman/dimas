#include <stdio.h>

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

int main(){
	int a[4],i,j;
	while (scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3])!=EOF){
		qsort(a,4,sizeof(int),cmp);
		for (i=0;i<4;i++){
			for (j=0;j<6;i++){
				printf("%d",a[i]);
				
			}
			putchar('\n');
		}
	}
	return 0;
}
