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
    int Y,M,D;
}stu;

int cmp(const void *a,const void *b){
    int y=(*(stu**)a)->Y-(*(stu**)b)->Y,m=(*(stu**)a)->M-(*(stu**)b)->M,d=(*(stu**)a)->D-(*(stu**)b)->D;
	return y?y:(m?m:d);
}

stu* list[110];

int main() {
    int n,i;stu *temp;
    while (~scanf("%d",&n)) {
        for (i=0;i<n;i++){
            temp=(stu*)malloc(sizeof(stu));
            scanf("%d/%d/%d",&temp->M,&temp->D,&temp->Y);
            list[i]=temp;
        }
        qsort(list,n,sizeof(stu*),cmp);
        for (i=0;i<n;i++) printf("%02d/%02d/%04d\n",list[i]->M,list[i]->D,list[i]->Y);
    }
    return 0;
}