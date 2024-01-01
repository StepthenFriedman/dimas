#include <stdio.h>
#include <stdlib.h>
#define DULPLICATE 2
void quicksort(void *start,void *end,unsigned long size,int (*cmp)(const void *,const void *));
void copy(void *dest, void *src,unsigned long size){
    char *d=dest,*s=src;
    while (size--) *d++ = *s++;
}
void swap(void *a, void *b,unsigned long size){
    char *ac=a,*bc=b,tmp;
    while (size--){
	  tmp = *ac;
	  *ac++ = *bc;
	  *bc++ = tmp;
	}
}
unsigned int cast(const void *a) {
    return *(unsigned int*)a;
}
unsigned int getmax(void *start,void *end,unsigned long size,unsigned int (*cast)(const void *)){
    unsigned int max=0,temp;
    for (void *i=start;i<=end;i+=size){
        temp=cast(i);
        if (max<temp) max=temp;
    }
    return max;
}

void bucketsort(void *start,void *end,unsigned long size,unsigned int bucketlen,unsigned int (*cast)(const void *)){
    int cmp(const void * a,const void * b){return cast(b)-cast(a);}
    int len=(getmax(start,end,size,cast)/bucketlen)+1,j;
    void** temp=malloc(len*sizeof(void*));
    char* count=calloc(len,sizeof(char));
    for (void *i=start;i<=end;i+=size){
        if (!count[cast(i)/bucketlen]){
            void* inner=malloc(bucketlen*DULPLICATE*size);
            copy(inner,i,size);
            count[cast(i)/bucketlen]++;
            temp[cast(i)/bucketlen]=inner;
        }else copy(temp[cast(i)/bucketlen]+(count[cast(i)/bucketlen]++)*size,i,size);
    }
    for (j=0;j<len;j++) quicksort(temp[j],temp[j]+count[j]*size,size,cmp);
    void *iter=start;
    for (j=0;j<len;j++) while (count[j]--) copy(iter,temp[j]+count[j]*size,size),iter+=size;
}
void bsort(void *start,unsigned long total_elem,unsigned long size,unsigned long bucketlen,unsigned int (*cast)(const void *)){
    if (!total_elem) return;
    bucketsort(start,start+(total_elem-1)*size,size,bucketlen,cast);
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

int main(){
    unsigned int a[]={2,3,5,1,7,8,11,2,4,13,20,32,53,60,100,1100,23,10032,4,59,280,6},i;
    bsort(a,sizeof(a)/sizeof(int),sizeof(int),10,cast);
    for (i=0;i<sizeof(a)/sizeof(int);i++) printf("%d ",a[i]);
}