#include<stdio.h>
#include <stdlib.h>

typedef struct ListNode{
	int value;
	struct ListNode* next;
} LN;

int main(){
	int n,sum=0,add,times,max,min,ipt,temp;
	register int i;
	LN* next;
	scanf("%d",&n);
	int* sort=calloc(1000000,sizeof(int));
	scanf("%d",&ipt);max=min=ipt;sort[ipt]++;
	for(i=1;i<n;i++){
		scanf("%d",&ipt);
		max=max>ipt?max:ipt;
		min=min<ipt?min:ipt;
		sort[ipt]++;
	}
	LN* node=(LN*)malloc(sizeof(LN)),*head=node,*search=node,*del=node,*tmp;
	node->value=min;
    for (i=min+1;i<=max;i++){
		while (sort[i]) {
			LN* a=(LN*)malloc(sizeof(LN));
			node->next=a;
			a->value=i;
			node=node->next;
			sort[i]--;
		}
	}
	search=search->next->next;
	node->next=NULL;
	for (times=0;times<n-1;times++){
		temp=head->value;
		head=head->next;
		temp+=head->value;
		head=head->next;
		sum+=temp;
		while (search->next!=NULL){
			if (((search->next)->value)>=temp) break;
			search=search->next;
		}
		LN* a=(LN*)malloc(sizeof(LN));
		(a->value)=temp;
		(a->next)=(search->next);
		(search->next)=del=a;
	}
	while (del!=NULL){
		tmp=del;del=del->next;free(tmp);
	}
	free(sort);
	printf("%d\n",sum);
	return 0;
}
