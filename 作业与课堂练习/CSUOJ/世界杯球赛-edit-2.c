#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct team{
    char name[30];int match,ball;
}team;

int cmp(const void* a,const void* b){
    team *ta=*(team**)a,*tb=*(team**)b;
    int res=(tb->match)-(ta->match);
    int res2=(tb->ball)-(ta->ball);
    return res?res:(res2?res2:strcmp(ta->name,tb->name));
}

team *list[20];

int main(){
    team *temp;
    int n,i,j,k,len,ipt3,ipt4,team1,team2,matchTimes;
    char ipt1[30],ipt2[30];
    while (~scanf("%d",&n)){
        matchTimes=(n*(n-1))/2;
        for (len=i=0;i<matchTimes;i++){
            scanf("%s %d:%d",ipt1,&ipt3,&ipt4);
            for (j=0;ipt1[j]!=':';j++);
            ipt1[j]='\0';
            for (j++,k=0;ipt1[j]!='\0';j++) ipt2[k++]=ipt1[j];
            ipt2[k]='\0';
            for (j=0;j<len;j++) if (!strcmp(list[j]->name,ipt1)){
                team1=j;goto next;
            }
            temp=(team*)malloc(sizeof(team));
            strcpy(temp->name,ipt1);
            temp->match=temp->ball=0;
            team1=len;

            list[len++]=temp;
            next:
            for (j=0;j<len;j++) if (!strcmp(list[j]->name,ipt2)){
                team2=j;goto next2;
            }
            temp=(team*)malloc(sizeof(team));
            strcpy(temp->name,ipt2);
            temp->match=temp->ball=0;
            team2=len;

            list[len++]=temp;
            next2:

            list[team1]->ball+=ipt3,list[team2]->ball+=ipt4;
            if (ipt3==ipt4) list[team1]->match++,list[team2]->match++;
            else if (ipt3<ipt4) list[team2]->match+=3;
            else list[team1]->match+=3;
        }
        qsort(list,n,sizeof(team*),cmp);
        for (i=0;i<n;i++) printf("%s:(%d %d) ",list[i]->name,list[i]->match,list[i]->ball);
        putchar('\n');
    }
    return 0;
}