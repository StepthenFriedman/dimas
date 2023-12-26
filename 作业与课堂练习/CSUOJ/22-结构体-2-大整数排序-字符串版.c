#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int cmpnum(const char *a,const char *b,int i){
    if (a[i]=='\0') return 0;
    int res=a[i]-b[i];
	return res?res:cmpnum(a,b,i+1);
}
int cmplen(const void *a,const void *b){
    int res=strlen((char *)(*(char**)a))-strlen((char *)(*(char**)b));
	return res?res:cmpnum(*(char**)a,*(char**)b,0);
}

char ipt[1002];
char *list[300];
int main(){
	int i,j,n,length;char *heap;
	while (~scanf("%d",&n)){
        i=0;j=n;
        while (j--){
            scanf("%s",&ipt);
            heap=(char*)malloc((1002)*sizeof(char));
            strcpy(heap,ipt);
            list[i++]=heap;
        }
        qsort(list,n,sizeof(char *),cmplen);
        for (i=0;i<n;i++) printf("%s\n",list[i]);
	}
	return 0;
}
