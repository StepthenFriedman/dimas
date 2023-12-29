#include <stdio.h>
#include <stdlib.h>
#include <string.h>
void move(void *dest, void *src,unsigned long size){
    char *d=dest,*s=src;
    while (size--) *d++ = *s++;
}

void merge(void *start,void *mid,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    void *temp=malloc(end-start+size);
    void *i=start,*j=mid+size,*copy=temp,*fre=temp,*disp;
    while (i<=mid&&j<=end){
        if (cmp(i,j)<0) move(temp,i,size),temp+=size,i+=size;
        else            move(temp,j,size),temp+=size,j+=size;
    }
    while (i<=mid) move(temp,i,size),temp+=size,i+=size;
    while (j<=end) move(temp,j,size),temp+=size,j+=size;
    for (i=start;i<=end;i+=size,copy+=size) move(i,copy,size);
    free(fre);
}
void mergesort(void *start,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    if (end<=start+size) return;
    void* mid=start+((end-start)/(2*size))*size;
    mergesort(start,mid,size,cmp);
    mergesort(mid+size,end,size,cmp);
    merge(start,mid,end,size,cmp);
}
void msort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    mergesort(start,start+(total_elem-1)*size,size,cmp);
}
typedef struct stu{
    char name[12];
    int chin,math,eng,sum;
}stu;

int cmpchin(const void *b,const void *a){
	return (*(stu**)a)->chin-(*(stu**)b)->chin;
}
int cmpmath(const void *b,const void *a){
	return (*(stu**)a)->math-(*(stu**)b)->math;
}
int cmpeng(const void *b,const void *a){
	return (*(stu**)a)->eng-(*(stu**)b)->eng;
}
int cmpsum(const void *b,const void *a){
	return (*(stu**)a)->sum-(*(stu**)b)->sum;
}
int cmpname(const void *a,const void *b){
	return strcmp(a,b);
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
        //msort(list,n,sizeof(stu*),cmpname);
        msort(list,n,sizeof(stu*),cmpsum);
        for (i=0;i<3;i++) printf("%s %d\n",list[i]->name,list[i]->sum);
        putchar('\n');
        //msort(list,n,sizeof(stu*),cmpname);
        msort(list,n,sizeof(stu*),cmpchin);
        for (i=0;i<3;i++) printf("%s %d\n",list[i]->name,list[i]->chin);
        putchar('\n');
        //msort(list,n,sizeof(stu*),cmpname);
        msort(list,n,sizeof(stu*),cmpmath);
        for (i=0;i<3;i++) printf("%s %d\n",list[i]->name,list[i]->math);
        putchar('\n');
        //msort(list,n,sizeof(stu*),cmpname);
        msort(list,n,sizeof(stu*),cmpeng);
        for (i=0;i<3;i++) printf("%s %d\n",list[i]->name,list[i]->eng);
        putchar('\n');
    }
    return 0;
}