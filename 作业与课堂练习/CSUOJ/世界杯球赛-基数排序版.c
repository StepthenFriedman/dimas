#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct st{
    char name[100];
    int score;
    int cishu;
}node[1000]={0};

void copy(void *dest, void *src,unsigned long size){
    char *d=dest,*s=src;
    while (size--) *d++ = *s++;
}

unsigned short cast1(const void *a){
    return 65535-((struct st*)a)->score;
}

unsigned short cast2(const void *a){
    return 65535-((struct st*)a)->cishu;
}

unsigned short cast3(const void *a){
    return ((struct st*)a)->name[0];
}

unsigned short cast4(const void *a){
    char x=((struct st*)a)->name[1];
    if (x=='\0') return 0;
    return x;
}

void rsort_4priorities(void *start,unsigned long total_elem,unsigned long size,unsigned short(*cast1)(const void *),unsigned short(*cast2)(const void *),unsigned short(*cast3)(const void *),unsigned short(*cast4)(const void *)){
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

int main(){
    int n,flag=0;
    while(scanf("%d",&n)!=EOF){
        memset(node,0,sizeof(struct st)*flag) ;
        int ne=(n*(n-1))/2;
        char *p=NULL,*q=NULL,begi[1000],*sep=":";
        int s1,s2;flag=0;
        for(int i=0;i<ne;i++){
            scanf("%s %d:%d",begi,&s1,&s2);
            p=strtok(begi,sep);q=strtok(NULL,sep);
            for(int i=0;i<=flag;i++){
                if(strcmp(p,node[i].name)==0)goto n1;
            }
            strcpy(node[flag++].name,p);
            n1:;
            for(int i=0;i<=flag;i++){
                if(strcmp(q,node[i].name)==0)goto n2;
            }
            strcpy(node[flag++].name,q);
            n2:;
            for(int i=0;i<flag;i++){
                if(strcmp(p,node[i].name)==0){if(s1>s2){node[i].score+=3;node[i].cishu+=s1-s2;}if(s1==s2)node[i].score++;}
                if(strcmp(q,node[i].name)==0){if(s2>s1){node[i].score+=3;node[i].cishu+=s2-s1;}if(s1==s2)node[i].score++;}
            }
        }
        rsort_4priorities(node,flag,sizeof(struct st),cast1,cast2,cast3,cast4);
        for(int i=0;i<flag;i++)printf("%s ",node[i].name);
        printf("\n");
    }
    return 0;
}