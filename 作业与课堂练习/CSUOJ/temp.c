#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#pragma GCC optimize ("O3")

void copy(void *dest, void *src,unsigned long size){
    char *d=dest,*s=src;
    while (size--) *d++ = *s++;
}

unsigned char cast(const void *a,const unsigned long j){
    return (*(char**)a)[j];
}

void radixsort(void *start,void *end,void *startb,void *endb,unsigned long size,unsigned long digit,unsigned long *dsct_pos,unsigned long *dsct_num,unsigned char(*cast)(const void *,const unsigned long)){
    
    unsigned long sum[256]={0};

    memset(dsct_pos,0,sizeof(unsigned long)*(((end-start)/size)+1)/2);
    memset(dsct_num,0,sizeof(unsigned long)*(((end-start)/size)+1)/2);
    unsigned long  dsct_total = 0;

    int i; void* ptr;
	printf("before: "); for (ptr=start;ptr<end;ptr+=size) printf("%s ",*(char**)ptr);putchar('\n');

	for (i='a';i<='z';i++) printf("%d ",sum[i]); putchar('\n');

    for (ptr=start;ptr<end;ptr+=size) sum[cast(ptr,digit)]++;

	for (i='a';i<='z';i++) printf("%d ",sum[i]); putchar('\n');
    for (i=1;i<=255;i++){
        if (sum[i]>1) dsct_pos[dsct_total]=sum[i-1]*size,dsct_num[dsct_total++]=sum[i]*size;
        sum[i]+=sum[i-1];
    }

	for (i=0;i<dsct_total;i++) printf("%d:%d ",dsct_pos[i]/size,dsct_num[i]/size); putchar('\n');

    for (ptr=end-size;ptr>=start;ptr-=size)   copy(startb+(--sum[cast(ptr,digit)])*size,ptr,size);

	printf("after : "); for (ptr=startb;ptr<endb;ptr+=size) printf("%s ",*(char**)ptr);putchar('\n');putchar('\n');

    for (ptr=endb-size;ptr>=startb;ptr-=size) copy(start+(ptr-startb),ptr,size);
    for (i=0;i<dsct_total;i++) radixsort(start+dsct_pos[i],start+(dsct_pos[i]+dsct_num[i]),startb+dsct_pos[i],startb+(dsct_pos[i]+dsct_num[i]),size,digit+1,dsct_pos+(),dsct_num,cast);
    
}

void rsort(void *start,unsigned long total_elem,unsigned long size,unsigned char(*cast)(const void *,const unsigned long)){
    void *startb = (void*)malloc(size*total_elem);
    unsigned long *dsct_pos = (unsigned long*)calloc(total_elem,sizeof(unsigned long));
    unsigned long *dsct_num = (unsigned long*)calloc(total_elem,sizeof(unsigned long));
    radixsort(start,start+total_elem*size,startb,startb+total_elem*size,size,0,dsct_pos,dsct_num,cast);
    free(startb),free(dsct_pos),free(dsct_num);
}

int main(){
    int i;
    char *s1="abv",*s2="cnd",*s3="cdeg",*s4="degt",*s5="kaef",*s6="aeno",*s7="dav",*s8="abs";
    char *list[]={s1,s2,s3,s4,s5,s6,s7,s8};
    rsort(list,8,sizeof(char*),cast);
    for (i=0;i<8;i++) printf("%s\n",list[i]);
}