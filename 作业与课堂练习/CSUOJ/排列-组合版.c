#include <stdio.h>

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

int intoNum(int* a,int i,int j,int k,int l){
	return (a[i]*1000)+(a[j]*100)+(a[k]*10)+a[l];
} 


int main(){
	int a[4],i,j,k,l,last,now;
	while (scanf("%d %d %d %d",&a[0],&a[1],&a[2],&a[3])!=EOF){
		qsort(a,4,sizeof(int),cmp);
		last=0;
		for (i=0;i<4;i++) for (j=0;j<4;j++) for (k=0;k<4;k++) for (l=0;l<4;l++) if (i!=j&&j!=k&&k!=l&&i!=l&&i!=k&&j!=l){
			now=intoNum(a,i,j,k,l);
			if (last>=now||a[i]==0) continue;
			if (now/1000!=last/1000&&last) putchar('\n');
			last=now;
			printf("%d%d%d%d ",a[i],a[j],a[k],a[l]);
		}
		putchar('\n');
	}
	return 0;
}
