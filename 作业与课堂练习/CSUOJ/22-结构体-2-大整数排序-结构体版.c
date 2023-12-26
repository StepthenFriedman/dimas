#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct Big{
    int len;char * data;
}big;

int cmp2(const big *a,const big *b,int i){
    if ((a->data)[i]=='\0') return 0;
    int res=((a->data)[i])-((b->data)[i]);
	return res?res:cmp2(a,b,i+1);
}
int cmp1(const void *a,const void *b){
    int res=(((big *)a)->len)-(((big *)b)->len);
	return res?res:cmp2((big *)a,(big *)b,0);
}

big list[300];
char ipt[1010];
int main(){
	int i,j,n,length;char *heap;
	while (~scanf("%d",&n)){
        i=0;j=n;
        while (j--){
            scanf("%s",&ipt);
            length=strlen(ipt);
            heap=(char*)malloc((length+2)*sizeof(char));
            strcpy(heap,ipt);
            big temp={length,heap};
            list[i++]=temp;
        }
        qsort(list,n,sizeof(big),cmp1);
        for (i=0;i<n;i++) printf("%s\n",list[i].data);
	}
	return 0;
}
