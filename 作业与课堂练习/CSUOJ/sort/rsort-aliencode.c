#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma GCC optimize ("O3")

void rsort(unsigned *a, int len){
    unsigned *b = (unsigned *)malloc(sizeof(unsigned)*len);
    int sum[256]={0}, sum1[256]={0}, sum2[256]={0}, sum3[256]={0},q,i;
    for (i=0;i<len;i++){
        ++sum[a[i] & 255];
        ++sum1[(a[i] >> 8) & 255];
        ++sum2[(a[i] >> 16) & 255];
        ++sum3[a[i] >> 24];
    }
    for (q = 1; q <= 255; ++q){
        sum[q] += sum[q - 1];
        sum1[q] += sum1[q - 1];
        sum2[q] += sum2[q - 1];
        sum3[q] += sum3[q - 1];
    }
    for (q = len - 1; q >= 0; --q) b[--sum[a[q] & 255]] = a[q];
    for (q = len - 1; q >= 0; --q) a[--sum1[(b[q] >> 8) & 255]] = b[q];
    for (q = len - 1; q >= 0; --q) b[--sum2[(a[q] >> 16) & 255]] = a[q];
    for (q = len - 1; q >= 0; --q) a[--sum3[b[q] >> 24]] = b[q];
    free(b);
}

void rsort_float(float *ar, int len){
    unsigned  *a=(unsigned *)ar;
    unsigned *BUF = (unsigned *)malloc(sizeof(unsigned)*(len+1)),*b=BUF+1;
    *(float *)BUF=1.0;//guard
    int sum[256]={0}, sum1[256]={0}, sum2[256]={0}, sum3[256]={0},q;
    for (int i = 0; i < len; i++){
        ++sum[a[i] & 255];
        ++sum1[(a[i] >> 8) & 255];
        ++sum2[(a[i] >> 16) & 255];
        ++sum3[a[i] >> 24];
    }
    for (q = 1; q <= 255; ++q){
        sum[q] += sum[q - 1];
        sum1[q] += sum1[q - 1];
        sum2[q] += sum2[q - 1];
        sum3[q] += sum3[q - 1];
    }
    for (q = len - 1; q >= 0; --q) b[--sum[a[q] & 255]] = a[q];
    for (q = len - 1; q >= 0; --q) a[--sum1[(b[q] >> 8) & 255]] = b[q];
    for (q = len - 1; q >= 0; --q) b[--sum2[(a[q] >> 16) & 255]] = a[q];
    for (q = len - 1; q >= 0; --q) a[--sum3[b[q] >> 24]] = b[q];
    memcpy(b,a,sizeof(unsigned)*len);
    int beg=len-1;q = beg;
    for (;b[q]&0x80000000; --q)
        a[beg-q]=b[q];
    memcpy(a+beg-q,b,sizeof(unsigned)*(q+1));
    free(BUF);
}

int main(){
    int len=sizeof(a)/sizeof(unsigned int);
    unsigned int a[]={2,3,5,1,7,8,11,2,4,13,20,32,53,60,100,1100,23,1003200000,4,59,280,6},i;
    rsort_noDulplicate(a,len);
    printf("finish!\n");
    for (i=0;i<len;i++) printf("%d ",a[i]);
}