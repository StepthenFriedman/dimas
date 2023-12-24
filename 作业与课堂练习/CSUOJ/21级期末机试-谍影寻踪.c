#include<stdio.h>
#include<string.h>
#include<stdlib.h>

typedef struct LN{
    int code;
    int name[100];
} LN;

LN *list[100000];
char temp[10];

size_t size=sizeof(LN);

int main(){
    int T,a,b,c,d,i,j,hh,tt;
    while (~scanf("%d", &T)){
        scanf("%d,%d->%d,%d",&a,&b,&c,&d);

        T--,hh=50000,tt=50001;

        LN* x=(LN*)malloc(size);
        LN* y=(LN*)malloc(size);

        memset(x->name,-1,100*sizeof(int));
        memset(y->name,-1,100*sizeof(int));

        x->name[0]=b;
        x->code=a;

        y->name[0]=d;
        y->code=c;

        list[hh]=x;
        list[tt++]=y;

        while(T--){
            scanf("%d,%d->%d,%d",&a,&b,&c,&d);
            if (list[tt-1]->code==a){
                LN* n=(LN*)malloc(size);

                memset(n->name,-1,100*sizeof(int));

                n->name[0]=d;
                n->code=c;
                for (i=0;list[tt-1]->name[i]!=-1;i++) if (list[tt-1]->name[i]==b) goto skip1;
                list[tt-1]->name[i]=b;
                skip1:list[tt++]=n;
            }else if (list[hh]->code==c){
                LN* n=(LN*)malloc(size);

                memset(n->name,-1,100*sizeof(int));

                n->name[0]=b;
                n->code=a;
                for (i=0;list[hh]->name[i]!=-1;i++) if (list[hh]->name[i]==d) goto skip2;
                list[hh]->name[i]=d;
                skip2:list[--hh]=n;
            }else for (j=hh;j<tt;j++){
                if (list[j]->code==a){
                    for (i=0;list[j]->name[i]!=-1;i++) if (list[j]->name[i]==b) goto skip3;
                    skip3:list[j]->name[i]=b;
                    for (i=0;list[j+1]->name[i]!=-1;i++) if (list[j+1]->name[i]==d) goto skip4;
                    skip4:list[j+1]->name[i]=d;
                    break;
                }
            }
        }
        for (i=hh;i<tt;i++){
            printf("->%d,"+2*(!(i-hh)),list[i]->code);
            for (j=0;list[i]->name[j]!=-1;j++){
                printf("#%d"+!j,list[i]->name[j]);
            }
        }
        putchar('\n');
    }
    
	return 0;
}
