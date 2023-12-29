#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void swap(void *a, void *b,unsigned long size){
    char *ac=a,*bc=b,tmp;
    while (size--){
	  tmp = *ac;
	  *ac++ = *bc;
	  *bc++ = tmp;
	}
}

void quicksort(void *start,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    if (end<=start) return;
    void *base=start,*i=start,*j=end;
    while (i<j){
        while (cmp(j,base)>=0&&i<j) j-=size;
        while (cmp(i,base)<=0&&i<j) i+=size;
        swap(i,j,size);
    }
    swap(base,j,size);
    quicksort(start,j-size,size,cmp);
    quicksort(j+size,end,size,cmp);
}
void qsort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    quicksort(start,start+(total_elem-1)*size,size,cmp);
}

typedef struct stu{
    char name[12];
    int chin,math,eng,sum;
}stu;

int cmpname(const void *b,const void *a){
	return strcmp((*(stu**)b)->name,(*(stu**)a)->name);
}
int cmpchin(const void *b,const void *a){
	int res= (*(stu**)a)->chin-(*(stu**)b)->chin;
    return res?res:cmpname(b,a);
}
int cmpmath(const void *b,const void *a){
	int res= (*(stu**)a)->math-(*(stu**)b)->math;
    return res?res:cmpname(b,a);
}
int cmpeng(const void *b,const void *a){
    int res=(*(stu**)a)->eng-(*(stu**)b)->eng;
	return res?res:cmpname(b,a);
}
int cmpsum(const void *b,const void *a){
    int res=(*(stu**)a)->sum-(*(stu**)b)->sum;
	return res?res:cmpname(b,a);
}

stu* list[110];

int main() {
    int n,i;stu *temp;
    while (~scanf("%d",&n)) {
        for (i=0;i<n;i++){
            temp=(stu*)malloc(sizeof(stu));
            scanf("%s%d%d%d",&temp->name,&temp->chin,&temp->math,&temp->eng);
            temp->sum=temp->chin+temp->math+temp->eng;
            list[i]=temp;
        }
        qsort(list,n,sizeof(stu*),cmpsum);
        for (i=0;i<3;i++) printf("%s %d\n",list[i]->name,list[i]->sum);
        putchar('\n');
        qsort(list,n,sizeof(stu*),cmpchin);
        for (i=0;i<3;i++) printf("%s %d\n",list[i]->name,list[i]->chin);
        putchar('\n');
        qsort(list,n,sizeof(stu*),cmpmath);
        for (i=0;i<3;i++) printf("%s %d\n",list[i]->name,list[i]->math);
        putchar('\n');
        qsort(list,n,sizeof(stu*),cmpeng);
        for (i=0;i<3;i++) printf("%s %d\n",list[i]->name,list[i]->eng);
        putchar('\n');
    }
    return 0;
}