#include<stdio.h>
#include<stdlib.h>

typedef struct LN{
    int value;
    struct LN* next;
} LN;

int main(){
    LN* head,*fr; char last; int ipt;
    nextline:head=NULL;
    nextword:scanf("%d",&ipt);
    LN* newln=(LN*)malloc(sizeof(LN));
    newln->value=ipt;
    newln->next=head;
    head=newln;
    last=getchar();
    if (last==' ') goto nextword;
    else if (last=='\n'||last==EOF){
    	while (head!=NULL) {
            printf("%d ",head->value);
            fr=head;
            head=head->next;
            free(fr);
        }
		putchar('\n');
    	if (last=='\n') goto nextline;
	}
    return 0;
}

