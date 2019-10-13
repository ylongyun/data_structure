/*约瑟夫问题的一种描述是:编号为1.2..n的n个人按顺时针方向围坐一圈,每人持有一个密码(正整数)。
开始时任选一个整数作为报数上值m,从第一个人开始顺时针自1开始顺序报数，报到m时停止报数。
报m的人出列，将他的密码作为新的m值,从他在顺时针方向上的下一个人开始重新从1报数，如此下去,
直至所有的人全部出列为止。试设计一个程序,求出出列顺序。




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
