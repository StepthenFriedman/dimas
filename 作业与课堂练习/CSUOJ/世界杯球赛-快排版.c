#include<stdio.h>
#include<string.h>
//#include<stdlib.h>

struct st{
    char name[100];
    int score;
    int cishu;
}node[1000]={0};

int cmp(const void *a,const void *b){
    if(((struct st*)a)->score!=((struct st*)b)->score)
    return ((struct st*)b)->score-((struct st*)a)->score;
    else if(((struct st*)a)->cishu!=((struct st*)b)->cishu)
    return ((struct st*)b)->cishu-((struct st*)a)->cishu;
    else {
        int dis=0;
        while (dis<30&&((struct st*)a)->name[dis]==((struct st*)b)->name[dis]) dis++;
        return ((struct st*)a)->name[dis]-((struct st*)b)->name[dis];
    }
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
void qsort(void *start,unsigned long total_elem,unsigned long size,int (*cmp)(const void *,const void *)){
    quicksort(start,start+(total_elem-1)*size,size,cmp);
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
        qsort(node,flag,sizeof(struct st),cmp);
        for(int i=0;i<flag;i++)printf("%s ",node[i].name);
        printf("\n");
    }
    return 0;
}