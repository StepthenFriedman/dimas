#include <stdio.h>

int main(){
	int a[1000],i,j,k;double sqt;
	for (i=1;k<1000;i++){
		sqt=sqrt((double)i);
		for (j=2;(double)j<=sqt;j++){
			if (!(i%j)) goto next;
		}
		a[k++]=i;
		next:i=i;
	}
	for (i=1;i<1000;i++) printf("%d, ",a[i]);
	return 0;
}
