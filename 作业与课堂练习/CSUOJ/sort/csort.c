#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma GCC optimize ("O3")


unsigned char cast(const void *a){
    return (*(char**)a)[0];
}

void countingsort_rmDulplicate_long(unsigned long *arr,unsigned long *len){
    unsigned long long* exist=calloc(67108864,sizeof(unsigned long long)),j2;
    int i,j,k=0,max=0;
    for (i=0;i<*len;i++){
        exist[arr[i]/64]|=1ULL<<(arr[i]%64);
        if (max<arr[i]) max=arr[i];
    }
    for (i=0;i<=max/64;i++) if (exist[i]) for (j=0;j<64;j++) if (exist[i]&(1ULL<<j)) arr[k++]=i*64+j;
    *len=k;
    free(exist);
}

void countingsort_rmDulplicate_short(unsigned long *arr,unsigned long *len){
    unsigned long long exist[1024]={0};
    int i,j,k=0,temp1,temp2;
    for (i=0;i<*len;i++) exist[arr[i]/64]|=1<<(arr[i]%64);
    for (i=0;i<1024;i++) if (exist[i]) for (j=0;j<64;j++) if (exist[i]&(1ULL<<j)) arr[k++]=i*64+j;
    *len=k;
}

int main(){
    unsigned long arr[]={10,9,8,7,6,5,5,5,2,1,122222,122222222,1222222222,2147483647},i,len=14;
    countingsort_rmDulplicate_long(arr,&len);
    for (i=0;i<len;i++) printf("%lu ",arr[i]);putchar('\n');
}