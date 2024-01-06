#include <stdio.h>
int routine[100000]={1,1};
void findround(int *len,int m){
	for(int i=2;;i++){
        routine[i]=(routine[i-1]%m+routine[i-2]%m)%m;
		if(routine[i]==1&&routine[i-1]==1) {*len=i-1;return;}
	}
}
int main(){
    int len,*ptr,i;
    findround(&len,100);
    printf("len:%d\n",len);
    for (i=0;i<len;i++) printf("%d ",routine[i]);
    putchar('\n');
    printf("%d\n",routine[99]);
}