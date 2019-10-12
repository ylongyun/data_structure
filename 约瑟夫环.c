/*



*/ 
#include <stdio.h>
#include <stdlib.h>
typedef struct Node
{
	int order;
	int code;
	struct Node* next;

}LinkList;

LinkList *create (int length)
{
	int i;
	LinkList *head,*node,*pre;
	head=(LinkList*)malloc(sizeof(LinkList));
	head->next=NULL;
	pre=head;
	for (i=1;i<=length;i++)
	{
		node=(LinkList*)malloc(sizeof(LinkList));
		node->order=i;
		scanf("%d",&node->code);
		pre->next=node;
		pre=node;
		node->next=NULL;
	}
	node->next=head->next;
	return head->next;
}

int yuesefu(LinkList* head,int m)
{
	int i;
	LinkList* pre,* node;
	pre = head;
	while(head->next != head)
	{
		if(m != 1)
		{
			for(i = 1;i < (m-1);i++)
			{
			pre = pre->next; 
			}
			node = pre->next;
		
		}
		else{
			pre = head->next;
			while(pre->next != head){
				pre = pre->next;
			}
			node = head;
		}
		printf("%d\t",node->order);	
		pre->next = node->next;
		head = node->next;
		pre = head;
		m = node->code;
	}
	printf("%d\n",head->order);
	return 0;
}

int main()
{
	LinkList* head;
	head=create(7);
	yuesefu(head,20);
	return 0;
}