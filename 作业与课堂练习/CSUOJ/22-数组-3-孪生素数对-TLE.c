#include <stdio.h>
#include <math.h>

int prime[348520]={3};

int main(){
    int T,L,R,i,j,k,t,pr=1,sqt;
    for (i=3;prime[pr-1]<5000011;i+=2){
		sqt=(int)sqrt((double)i)+1;
		for (j=2;j<=sqt;j++) if (!(i%j)) goto next;
		prime[pr++]=i;
		next:i=i;
	}
    scanf("%d",&T);
    for (t=0;t<T;t++) {
        scanf("%d%d",&L,&R);
        for (k=i=0;prime[i]<L;i++);
        for (j=i+1;prime[j]<=R;j++) k+=(prime[j]-prime[j-1]==2);
        printf("%d\n",k);
    }
}