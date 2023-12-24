#include<stdio.h>
#include<stdlib.h>

typedef struct ListNode{
    int value;
    struct ListNode* next;
} LN;

int main(){
    LN *head,*nxt,*tail,*prev,*fr; char last; int ipt,first;
    nextline:first=1;head=NULL;
    nextword:scanf("%d",&ipt);
    LN* newln=(LN*)malloc(sizeof(LN));
    newln->value=ipt;
    newln->next=NULL;
    head->next=newln;
    if (!first) =newln;
    else 
    last=getchar();
    first=0;
    if (last==' ') goto nextword;
    else if (last=='\n'){
    	while (head!=NULL) {
            printf("%d ",head->value);
            fr=head;
            head=head->next;
            free(fr);
        }
		putchar('\n');
    	goto nextline;
	} 
    return 0;
}

