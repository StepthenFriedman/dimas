#include <stdio.h>
#include <stdlib.h>
void copy(void *dest, void *src,unsigned long size){
    char *d=dest,*s=src;
    while (size--) *d++ = *s++;
}

void merge(void *start,void *mid,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    void *temp=malloc(end-start+size);
    void *i=start,*j=mid+size,*cpy=temp,*fre=temp,*disp;
    while (i<=mid&&j<=end){
        if (cmp(i,j)<0) copy(temp,i,size),temp+=size,i+=size;
        else            copy(temp,j,size),temp+=size,j+=size;
    }
    while (i<=mid) copy(temp,i,size),temp+=size,i+=size;
    while (j<=end) copy(temp,j,size),temp+=size,j+=size;
    for (i=start;i<=end;i+=size,cpy+=size) copy(i,cpy,size);
    free(fre);
}
void mergesort(void *start,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    if (end<=start) return;
    void* mid=start+((end-start)/(2*size))*size;
    mergesort(start,mid,size,cmp);
    mergesort(mid+size,end,size,cmp);
    merge(start,mid,end,size,cmp);
}
void msort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    mergesort(start,start+(total_elem-1)*size,size,cmp);
}

int cmp(const void * a,const void * b){
    return *(int*)a-*(int*)b;
}
int main(){
    int a[11]={2,3,5,1,7,8,10,2,4,9,6},i;
    msort(a,10,sizeof(int),cmp);
    for (i=0;i<11;i++) printf("%d ",a[i]);
}