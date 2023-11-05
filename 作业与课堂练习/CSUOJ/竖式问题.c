#include <stdio.h>
#include <string.h>

//注意:输入可能大于四位数 

int cmp(const void *a,const void *b){
	return *(int*)a-*(int*)b;
}

int match(int* a,int x,int head){
	if (!x) {
		for (int j=head;j<10;j++) if (a[j]==0) return 1;
		return 0;
	}
	for (int i=0;x;i++){
		for (int j=head;j<10;j++){
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
	int a[10],i,j,k,l,m, p1,p2,r1,r2,r3, head,item, lp1,lp2;
	char x[10];
	while (scanf("%s",&x)!=EOF){
		memset(a,-1,10*sizeof(int));item=1;
		for (i=0;x[i]!='\0';i++) a[i]=x[i]-48;
		qsort(a,10,sizeof(int),cmp);
		for (i=1;i<10;i++) if (a[i-1]==a[i]) a[i-1]=-1;
		qsort(a,10,sizeof(int),cmp);
		for (head=0;a[head]==-1;head++);
		lp1=lp2=-1;
		for (i=head;i<10;i++) if (a[i]) for (j=head;j<10;j++) for (k=head;k<10;k++){
			for (l=head;l<10;l++) if (a[l]) for (m=head;m<10;m++) {
				p1=(a[i]*100+a[j]*10+a[k]);p2=(a[l]*10+a[m]);
				r1=(p1*a[m]);r2=(p1*a[l]);r3=(p1*p2);
				if (match(a,r1,head)&&match(a,r2,head)&&match(a,r3,head)&&(lp1<p1||lp2!=p2)){
					printf("<%d>\n  %3d\nX  %2d\n-----\n%5d\n%4d\n-----\n%5d\n\n",item,p1,p2,r1,r2,r3);
					item++;lp1=p1;lp2=p2;
				}
			}
		}
		printf("The number of solutions: %d\n",item-1);
	}
	return 0;
}
