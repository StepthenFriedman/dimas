#include <stdio.h>
#include <stdlib.h>

long long count;

void copy(void *dest, void *src,unsigned long size){
    char *d=dest,*s=src;
    while (size--) *d++ = *s++;
}

void merge(void *start,void *mid,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    void *temp=malloc(end-start+size);
    void *i=start,*j=mid+size,*cpy=temp,*fre=temp,*disp;
    while (i<=mid&&j<=end){
        if (cmp(i,j)<=0) copy(temp,i,size),count+=(int)((j-mid)/size)-1,temp+=size,i+=size;
        else            copy(temp,j,size),temp+=size,j+=size;
    }
    while (i<=mid) copy(temp,i,size),count+=(int)((j-mid)/size)-1,temp+=size,i+=size;
    while (j<=end) copy(temp,j,size),temp+=size,j+=size;
    for (i=start;i<=end;i+=size,cpy+=size) copy(i,cpy,size);
    free(fre);
}
void mergesort(void *start,void *end,unsigned long size,int (*cmp)(const void *,const void *)){

    if (end<start+size) return;
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

int arr[5*100000];
int main(){
    int n,i;
    count=0;
    scanf("%d",&n);
    for (i=0;i<n;i++) scanf("%d",&arr[i]);
    msort(arr,n,sizeof(int),cmp);
    printf("%lld\n",count);
    return 0;
}
