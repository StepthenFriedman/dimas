#include<stdio.h>
#include<string.h>
#include<math.h>
#include<stdlib.h>
typedef struct NODE
{
	int v;
	struct NODE *next;
} Node;
Node* add_node(Node *head,int n)
{
	Node *new_node=(Node*)malloc(sizeof(Node));
	new_node->v =n;
	new_node->next =head;
	return new_node;
}
void print_list(Node *head)
{
	Node *tem;
	for(tem=head; tem!=NULL; tem=tem->next )
		printf("%d ",tem->v );
	printf("\n");
}
int main()
{
	int n;
	char c;
	Node *head=(Node*)malloc(sizeof(Node));
	head=NULL;
	while(scanf("%d",&n)!=EOF)
	{
		head=add_node(head,n);
		if(scanf("%c",&c)==EOF||c=='\n')
		{
			print_list(head);
			head=NULL;
		}
	}
	return 0;
}