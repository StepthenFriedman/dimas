#include<stdio.h>
#include <stdlib.h>

typedef struct ListNode{
	int value;
	struct ListNode* next;
} LN;

int main(){
	int n,sum=0,add,times,max,min,ipt,i;
	LN* next;
	scanf("%d",&n);
	int* sort=calloc(1001,sizeof(int));
	scanf("%d",&ipt);max=min=ipt;sort[ipt]++;
	for(i=1;i<n;i++){
		scanf("%d",&ipt);
		max=max>ipt?max:ipt;
		min=min<ipt?min:ipt;
		sort[ipt]++;
	}
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
	while (del!=NULL){
		tmp=del;del=del->next;free(tmp);
	}
	printf("%d\n",sum);
	return 0;
}
