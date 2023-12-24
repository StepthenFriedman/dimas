#include<stdio.h>
#include<stdlib.h>
struct node{
	int data;
	struct node* next;
}; 
struct node* head;
void insert(int x)
{
	struct node* temp=(struct node*)malloc(sizeof(struct node));
	temp->data=x;
	temp->next=head;
	head=temp;
}
void print()
{
	struct node* temp1=head;
	while(temp1!=NULL){
		printf("%d ",temp1->data);
		temp1=temp1->next;
	}
	printf("\n");
}

int main()
{
	head=NULL;
	int x;
	char c;
	while(scanf("%d",&x)!=EOF)
	{
		insert(x);
		if(scanf("%c",&c)==EOF||c=='\n'){
			print();
			main();
		}
	}
	return 0;
}