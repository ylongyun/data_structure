#include<stdio.h>
#include<stdlib.h>
typedef struct Node
{
	int order;
	int code;
	struct Node* next;

}LinkList;
int main()
{
	LinkList a1,a2,a3,a4,a5,a6,a7;
	LinkList* head;
	head = &a1;
	a1.next = &a2;a2.next = &a3;a3.next = &a4;a4.next = &a5;a5.next = &a6;a6.next = &a7;a7.next = &a1;
	a1.code = 3;a2.code = 1;a3.code = 7;a4.code = 2;a5.code = 4;a6.code = 8;a7.code = 4;
	a1.order = 1;a2.order = 2;a3.order = 3;a4.order = 4;a5.order = 5;a6.order = 6;a7.order = 7;
	yuesifu(head,20);
	return 0;
}
void yuesifu(LinkList* head,int m)
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
}

