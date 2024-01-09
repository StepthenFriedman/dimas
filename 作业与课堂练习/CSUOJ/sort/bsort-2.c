#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma GCC optimize ("O3")

void copy(void *dest, void *src,unsigned long size){
    char *d=dest,*s=src;
    while (size--) *d++ = *s++;
}

unsigned char cast(const void *a){
    return (*(char**)a)[0];
}

int cmp(const void *a,const void *b){
    return strcmp(*(char**)a,*(char**)b);
}

void swap(void *a, void *b,unsigned long size){
    char *ac=a,*bc=b,tmp;
    while (size--){
	  tmp = *ac;
	  *ac++ = *bc;
	  *bc++ = tmp;
	}
}

void quicksort(void *start,void *end,unsigned long size,int (*cmp)(const void *,const void *)){
    if (end<=start+size) return;
    void *base=start,*i=start,*j=end-size;
    while (i<j){
        while (cmp(j,base)>=0&&i<j) j-=size;
        while (cmp(i,base)<=0&&i<j) i+=size;
        swap(i,j,size);
    }
    swap(base,j,size);
    quicksort(start,j,size,cmp);
    quicksort(j+size,end,size,cmp);
}

void bucketsort_char(void *start,void *end,void *startb,void *endb,unsigned long total_elem,unsigned long size,unsigned char(*cast)(const void *),int (*cmp)(const void *,const void *)){
    int sum[256]={0};
    unsigned long *dsct_pos = (unsigned long*)calloc(total_elem/2,sizeof(unsigned long)),
                  *dsct_num = (unsigned long*)calloc(total_elem/2,sizeof(unsigned long)),
                   dsct_total = 0;

    int i; void* ptr;

    for (ptr=start;ptr<end;ptr+=size) sum[cast(ptr)]++;
    for (i=1;i<256;i++){
        if (sum[i]>1) dsct_pos[dsct_total]=sum[i-1]*size,dsct_num[dsct_total++]=sum[i]*size;
        sum[i]+=sum[i-1];
    }

    for (ptr=end-size;ptr>=start;ptr-=size)   copy(startb+(--sum[cast(ptr)])*size,ptr,size);
    for (ptr=endb-size;ptr>=startb;ptr-=size) copy(start+(ptr-startb),ptr,size);
    for (i=0;i<dsct_total;i++) quicksort(start+dsct_pos[i],start+(dsct_pos[i]+dsct_num[i]),size,cmp);
    free(dsct_pos),free(dsct_num);
}

void bsort_char(void *start,unsigned long total_elem,unsigned long size,unsigned char(*cast)(const void *),int (*cmp)(const void *,const void *)){
    void *startb = (void*)malloc(size*total_elem);
    bucketsort_char(start,start+total_elem*size,startb,startb+total_elem*size,total_elem,size,cast,cmp);
    free(startb);
}

void bucketsort_short(void *start,void *end,void *startb,void *endb,unsigned long total_elem,unsigned long size,unsigned short(*cast)(const void *),int (*cmp)(const void *,const void *)){
    int sum[65536]={0};
    unsigned long dsct_len=((end-start)/size+1)/2,
                 *dsct_pos = (unsigned long*)calloc(dsct_len,sizeof(unsigned long)),
                 *dsct_num = (unsigned long*)calloc(dsct_len,sizeof(unsigned long)),
                  dsct_total = 0;

    int i; void* ptr;

    for (ptr=start;ptr<end;ptr+=size) sum[cast(ptr)]++;
    for (i=1;i<65536;i++){
        if (sum[i]>1) dsct_pos[dsct_total]=sum[i-1]*size,dsct_num[dsct_total++]=sum[i]*size;
        sum[i]+=sum[i-1];
    }

    for (ptr=end-size;ptr>=start;ptr-=size)   copy(startb+(--sum[cast(ptr)])*size,ptr,size);
    for (ptr=endb-size;ptr>=startb;ptr-=size) copy(start+(ptr-startb),ptr,size);
    for (i=0;i<dsct_total;i++) quicksort(start+dsct_pos[i],start+(dsct_pos[i]+dsct_num[i]),size,cmp);
    free(dsct_pos),free(dsct_num);
}

void bsort_short(void *start,unsigned long total_elem,unsigned long size,unsigned short(*cast)(const void *),int (*cmp)(const void *,const void *)){
    void *startb = (void*)malloc(size*total_elem);
    bucketsort_short(start,start+total_elem*size,startb,startb+total_elem*size,total_elem,size,cast,cmp);
    free(startb);
}

void bucketsort_E6(void *start,void *end,void *startb,void *endb,unsigned long total_elem,unsigned long size,unsigned long(*cast)(const void *),int (*cmp)(const void *,const void *)){
    unsigned char* sum=calloc(1000000,sizeof(unsigned char));
    unsigned long dsct_len=((end-start)/size+1)/2,
                 *dsct_pos = (unsigned long*)calloc(dsct_len,sizeof(unsigned long)),
                 *dsct_num = (unsigned long*)calloc(dsct_len,sizeof(unsigned long)),
                  dsct_total = 0;

    int i; void* ptr;

    for (ptr=start;ptr<end;ptr+=size) sum[cast(ptr)]++;
    for (i=1;i<1000000;i++){
        if (sum[i]>1) dsct_pos[dsct_total]=sum[i-1]*size,dsct_num[dsct_total++]=sum[i]*size;
        sum[i]+=sum[i-1];
    }

    for (ptr=end-size;ptr>=start;ptr-=size)   copy(startb+(--sum[cast(ptr)])*size,ptr,size);
    for (ptr=endb-size;ptr>=startb;ptr-=size) copy(start+(ptr-startb),ptr,size);
    for (i=0;i<dsct_total;i++) quicksort(start+dsct_pos[i],start+(dsct_pos[i]+dsct_num[i]),size,cmp);
    free(dsct_pos),free(dsct_num),free(sum);
}

void bsort_E6(void *start,unsigned long total_elem,unsigned long size,unsigned long(*cast)(const void *),int (*cmp)(const void *,const void *)){
    void *startb = (void*)malloc(size*total_elem);
    bucketsort_E6(start,start+total_elem*size,startb,startb+total_elem*size,total_elem,size,cast,cmp);
    free(startb);
}

int main(){
    int i;
    char *s1="abv",*s2="cnd",*s3="cdeg",*s4="degt",*s5="kaef",*s6="aeno",*s7="dav",*s8="abs",*s9="dau";
    char *list[]={s1,s2,s3,s4,s5,s6,s7,s8,s9};
    bsort_char(list,9,sizeof(char*),cast,cmp);
    for (i=0;i<9;i++) printf("%s\n",list[i]);
}