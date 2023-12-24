#include <stdio.h>
#include <math.h>
#define LEN 5000000

int a[LEN/5];
int pair[LEN/6]={0};

void prep(){
    int i,*j,k=0,amount,sqt,*st=&a[2],p,q;
    a[0]=2,a[1]=3,a[2]=5;
    for (amount=2,i=5;i<LEN;i+=6,k++){
        sqt=sqrt(i+2);p=q=0;
        for (j=st;*j<=sqt;j++) if (!(i%*j)) goto next1;
        a[amount++]=i;
		p=1;
        next1:;
        i+=2;
        for (j=st;*j<=sqt;j++) if (!(i%*j)) goto next2;
        a[amount++]=i;
		q=1;
        next2:;
        i-=2;
		pair[k+1]=pair[k]+(p&q);
    }
}

int main(){
	prep();
	int K,a,b;
	scanf("%d",&K);
	while(K--){
		scanf("%d%d",&a,&b);
		printf("%d\n",pair[(b-1)/6]-pair[a/6]+(a<=3&&b>=5));
	}
	return 0;
}