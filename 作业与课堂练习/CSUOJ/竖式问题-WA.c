#include <stdio.h>
#include <string.h>

//原来特么有5位数的输入!! 

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

int match(int* a,int x){
	if (!x) {
		for (int j=0;j<10;j++) if (a[j]==0) return 1;
		return 0;
	}
	for (int i=0;x;i++){
		for (int j=0;j<10;j++){
			if (x%10==a[j]){
				goto x;
			}
		}
		return 0;
		x:x/=10;
	}
	return 1;
}

int main(){
	int a[10],i,j,k,l,m, p1,p2,r1,r2,r3,x, item, lp1,lp2;
	while (scanf("%d",&x)!=EOF){
		memset(a,-1,sizeof(a));
		a[0]=0;
		item=1;lp1=lp2=0;
		for (i=0;i<10&&x;i++){
			a[i]=x%10;x/=10;
		}
		qsort(a,10,sizeof(int),cmp);
		for (i=0;i<10;i++) if (a[i]&&~a[i]) for (j=0;j<10;j++) if (~a[j]) for (k=0;k<10;k++) if (~a[k]) {
			for (l=0;l<10;l++) if (a[l]&&~a[l]) for (m=0;m<10;m++) if (~a[m]){
				p1=(a[i]*100+a[j]*10+a[k]);p2=(a[l]*10+a[m]);
				r1=(p1*a[m]);r2=(p1*a[l]);r3=(p1*p2);
				if (match(a,r1)&&match(a,r2)&&match(a,r3)&&(lp1<p1||lp2<p2)){
					printf("<%d>\n  %3d\nX  %2d\n-----\n%5d\n%4d\n-----\n%5d\n\n",item,p1,p2,r1,r2,r3);
					item++;lp1=p1;lp2=p2;
				}
			}
		}
		printf("The number of solutions: %d\n",item-1);
	}
	return 0;
}
