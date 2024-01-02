//contest id:1620

#include<stdio.h>
#include <stdlib.h>
#include<limits.h>

typedef struct ListNode{
	int value;
	//int dulplicate;
	struct ListNode* next;
} LN;

int main(){
	int n,sum=0,add,times,ipt,i;
	LN* next;
	scanf("%d",&n);
	int* sort=calloc(1002,sizeof(int));
	for(i=0;i<n;i++){
		scanf("%d",&ipt);
		sort[ipt]++;
	}/*
	LN* node=(LN*)malloc(sizeof(LN)),*head=node,*search=node,*del=node,*tmp;
	node->value=min;sort[min]--;
    for (i=min;i<=max;i++){
		while (sort[i]) {
			LN* a=(LN*)malloc(sizeof(LN));
			node->next=a;
			a->value=i;
			node=node->next;
			sort[i]--;
		}
	}
	free(sort);
	node->next=NULL;
	for (times=0;times<n-1;times++){
		add=head->value;
		head=head->next;
		add+=head->value;
		head=head->next;
		sum+=add;
		while (search->next!=NULL&&search->next->value<add) search=search->next;
		LN* a=(LN*)malloc(sizeof(LN));
		(a->value)=add;
		(a->next)=(search->next);
		(search->next)=a;
	}
	printf("%d\n",sum);*/
	printf("ok!\n");
	return 0;
}
