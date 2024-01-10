#include <stdio.h>
#include <stdlib.h>

void copy(void *dest, void *src,unsigned long size){
    char *d=dest,*s=src;
    while (size--) *d++ = *s++;
}

int cmp(const void * a,const void * b){
    return *(int*)a-*(int*)b;
}

void insertsort(void *start,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    void *sorted=start,*ptr=start+size,*change,*temp=(void*)malloc(size);
    for (;ptr<end;ptr+=size){
        change=ptr;
        copy(temp,change,size);
        while (change>start && cmp(change-size,temp)>0) copy(change,change-size,size),change-=size;
        copy(change,temp,size);
    }
    free(temp);
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

int main(){
    int a[]={10,9,8,7,6,5,4,3,2,1},i,len=sizeof(a)/sizeof(int);
    insertsort_skip(a,a+len,2,sizeof(int),cmp);
    for (i=0;i<len;i++) printf("%d ",a[i]);
}