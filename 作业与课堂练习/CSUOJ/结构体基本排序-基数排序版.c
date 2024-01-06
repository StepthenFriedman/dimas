#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct stu{
    int c,math,ele,sum;
    long long cmp;
    char * name;
}stu;

void copy(void *dest, void *src,unsigned long size){
    char *d=dest,*s=src;
    while (size--) *d++ = *s++;
}

unsigned short cast1(const void *a){
    return 65535-((stu*)a)->sum;
}

unsigned short cast2(const void *a){
    return ((stu*)a)->name[0];
}

unsigned short cast3(const void *a){
    return 65535-((stu*)a)->c;
}

unsigned short cast4(const void *a){
    return 0;
}

void rsort_4priorities_16bits(void *start,unsigned long total_elem,unsigned long size,unsigned short(*cast1)(const void *),unsigned short(*cast2)(const void *),unsigned short(*cast3)(const void *),unsigned short(*cast4)(const void *)){
    void *b = (void*)malloc(size*total_elem);unsigned long sum[4][65536]={0};
    int i;void *ptr=start,*end=start+(total_elem-1)*size,
               *startb=b,*endb=startb+(total_elem-1)*size;

    for (;ptr<=end;ptr+=size){
        sum[0][cast4(ptr)]++;
        sum[1][cast3(ptr)]++;
        sum[2][cast2(ptr)]++;
        sum[3][cast1(ptr)]++;
    }
    for (i=1;i<=65535;i++){
        sum[0][i]+=sum[0][i-1];
        sum[1][i]+=sum[1][i-1];
        sum[2][i]+=sum[2][i-1];
        sum[3][i]+=sum[3][i-1];
    }
    for (ptr=end;ptr>=start;ptr-=size)   copy(startb+(--sum[0][cast4(ptr)])*size,ptr,size);
    for (ptr=endb;ptr>=startb;ptr-=size) copy(start+ (--sum[1][cast3(ptr)])*size,ptr,size);
    for (ptr=end;ptr>=start;ptr-=size)   copy(startb+(--sum[2][cast2(ptr)])*size,ptr,size);
    for (ptr=endb;ptr>=startb;ptr-=size) copy(start+ (--sum[3][cast1(ptr)])*size,ptr,size);
    free(b);
}

stu list[300];
char ipt[1010];
int main(){
	int n,i,j, clang,mathmatic,eletric;char *heap;
    long long cmpnum;
	while (~scanf("%d",&n)){
        i=0;j=n;
        while (j--){
            scanf("%s%d%d%d",&ipt,&clang,&mathmatic,&eletric);
            heap=(char*)malloc((strlen(ipt)+2)*sizeof(char));
            strcpy(heap,ipt);
            cmpnum=(clang+mathmatic+eletric)*1000000+(125-ipt[0])*1000+clang;
            stu temp={clang,mathmatic,eletric,clang+mathmatic+eletric,cmpnum,heap};
            list[i++]=temp;
        }
        rsort_4priorities_16bits(list,n,sizeof(stu),cast1,cast2,cast3,cast4);
        for (i=0;i<n;i++) printf("%3d %20s %3d %3d %3d %3d\n",i+1,list[i].name,list[i].sum,list[i].c,list[i].math,list[i].ele),free(list[i].name);
	}
	return 0;
}
