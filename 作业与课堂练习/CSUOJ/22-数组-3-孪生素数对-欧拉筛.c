#include <stdio.h>
#include <math.h>
#define LEN 5000000

int a[LEN/2+5]={[0 ... LEN/2+4]=1};
int pair[LEN/6]={[0 ... LEN/6-1]=1};
void prep(){
    int i,j,lim,tmp;
    a[1]=a[2]=1;
    for (i=1;i<833333;i++) a[i*3+1]=0;
    for (i=2;i<1118;i++){
        lim=(LEN/(i*2+1))/2;
        for (j=2;j<=lim;j++) if (a[j]) {
            tmp=2*i*j+i+j;
            a[tmp]=0;
            
            pair[(tmp+1)/3]=0;
        }
    }
}

int main(){
	prep();/*
	int K,a,b;
	scanf("%d",&K);
	while(K--){
		scanf("%d%d",&a,&b);
		printf("%d\n",pair[(b-1)/6]-pair[a/6]+(a<=3&&b>=5));
	}*/
    for (int i=1;i<10;i++) printf("%d ",pair[i]);putchar('\n');
    for (int i=1;i<100;i++) if (a[i]) printf("%d, ",i*2+1);putchar('\n');
	return 0;
}