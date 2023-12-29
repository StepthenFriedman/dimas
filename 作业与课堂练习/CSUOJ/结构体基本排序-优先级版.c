#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stu{
    int c,math,ele,sum;
    long long cmp;
    char * name;
}stu;

int cmp1(const void *b,const void *a){
	return (((stu *)a)->cmp)-(((stu *)b)->cmp);
}
stu list[300];
char ipt[1010];
int main(){
	int n,i,j, clang,mathmatic,eletric;char *heap;
    long long cmpnum;
	while (~scanf("%d",&n)){
        i=0;j=n;
        while (j--){
            scanf("%s%d%d%d",&ipt,&clang,&mathmatic,&eletric);
            heap=(char*)malloc((strlen(ipt)+2)*sizeof(char));
            strcpy(heap,ipt);
            cmpnum=(clang+mathmatic+eletric)*1000000+(125-ipt[0])*1000+clang;
            stu temp={clang,mathmatic,eletric,clang+mathmatic+eletric,cmpnum,heap};
            list[i++]=temp;
        }
        qsort(list,n,sizeof(stu),cmp1);
        for (i=0;i<n;i++) printf("%3d %20s %3d %3d %3d %3d\n",i+1,list[i].name,list[i].sum,list[i].c,list[i].math,list[i].ele),free(list[i].name);
	}
	return 0;
}
