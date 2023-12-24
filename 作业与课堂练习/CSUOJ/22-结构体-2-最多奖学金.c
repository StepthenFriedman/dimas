#include<stdio.h>
#include<stdlib.h>

typedef struct LN{
    int name[100];
    int score;
} LN;

LN* list[10000];

int main(){
    int n,len=0,finalscore,commentscore,article,max=0,i;
    long long sum=0;
    char model,west;
	scanf("%d",&n);
    while (n--){
        LN* x=(LN*)malloc(sizeof(LN));
        scanf("%s%d%d %c %c%d",&x->name,&finalscore,&commentscore,&model,&west,&article);
        sum+=(x->score=8000*(article&&(finalscore>80))+
                 4000*((commentscore>80)&&(finalscore>85))+
                 2000*(finalscore>90)+
                 1000*((west=='Y')&&(finalscore>85))+
                  850*((model=='Y')&&(commentscore>80)));
        if (max<(x->score)) max=x->score;
        list[len++]=x;
    }
    for (i=0;i<len;i++) if (list[i]->score==max) {printf("%s\n",list[i]->name);break;}
    printf("%d\n%lld\n",max,sum);
}