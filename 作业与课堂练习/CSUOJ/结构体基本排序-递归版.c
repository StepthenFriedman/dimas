#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stu{
    int c,math,ele,sum;char * name;
}stu;

int cmp2(const stu *b,const stu *a){
    int res=((b->name)[0])-((a->name)[0]);
	return res?res:((a->c)-(b->c));
}
int cmp1(const void *b,const void *a){
    int res=(((stu *)a)->sum)-(((stu *)b)->sum);
	return res?res:cmp2((stu *)b,(stu *)a);
}

stu list[300];
char ipt[1010];
int main(){
	int n,i,j, clang,mathmatic,eletric;char *heap;
	while (~scanf("%d",&n)){
        i=0;j=n;
        while (j--){
            scanf("%s%d%d%d",&ipt,&clang,&mathmatic,&eletric);
            heap=(char*)malloc((strlen(ipt)+2)*sizeof(char));
            strcpy(heap,ipt);
            stu temp={clang,mathmatic,eletric,clang+mathmatic+eletric,heap};
            list[i++]=temp;
        }
        qsort(list,n,sizeof(stu),cmp1);
        for (i=0;i<n;i++) printf("%3d %20s %3d %3d %3d %3d\n",i+1,list[i].name,list[i].sum,list[i].c,list[i].math,list[i].ele);
	}
	return 0;
}
