#include <stdio.h>
#include <stdlib.h>

int main(){
	int n,m,i,a,b,len;
	while (~scanf("%d%d",&m,&n)){
        int* arr=calloc(10000,sizeof(int));
        len=0;
		for (i=0;i<m+n;i++){
            scanf("%d%d",&a,&b);
            if (len<b) len=b;
            arr[b]+=a;
        }
        for (i=len;i>-1;i--) if (arr[i]) printf("%d %d\n",arr[i],i);
	}
	return 0;
}
