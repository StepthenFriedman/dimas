#include <stdio.h>
#include <stdlib.h>

void copy(void *dest, void *src,unsigned long size){
    char *d=dest,*s=src;
    while (size--) *d++ = *s++;
}

int cmp(const void * a,const void * b){
    return *(int*)a-*(int*)b;
}

void insertsort_skip(void *start,void *end,unsigned long skip_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    void *sorted=start,*ptr=start+size*skip_elem,*change,*temp=(void*)malloc(size);
    for (;ptr<end;ptr+=size*skip_elem){
        change=ptr;
        copy(temp,change,size);
        while (change>start && cmp(change-size*skip_elem,temp)>0) copy(change,change-size*skip_elem,size),change-=skip_elem*size;
        copy(change,temp,size);
    }
    free(temp);
}

void ssort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    unsigned long gap,i;
    void *end=start+total_elem*size;
    for (gap=size/2;gap>0;gap/=2) for (i=0;i<gap;i++) insertsort_skip(start+size*i,end,gap,size,cmp);
}

int main(){
    int a[]={10,2,3,4,20,19,1024,3,5,5,29,3,5,64},i,len=sizeof(a)/sizeof(int);
    ssort(a,len,sizeof(int),cmp);
    for (i=0;i<len;i++) printf("%d ",a[i]);
}