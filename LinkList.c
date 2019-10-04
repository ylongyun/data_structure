#include <stdio.h>
#include <LinkList.h>
#include <stdlib.h>
LinkList* creatList(int n)
{
	LinkList* head;
	if (n == 0)//nΪ0�ļ�����һ��������
	{
		head = (LinkList*)malloc(sizeof(LinkList));
		head->next = NULL;//��սڵ�
		head->data = NULL;

	}
	else
	{
		int i,k;
		LinkList* node, * last;
		head = (LinkList*)malloc(sizeof(LinkList));
		last = head;
		for (i = 0;i < n;i++) {
			node = (LinkList*)malloc(sizeof(LinkList));//Ϊ�½ڵ㿪�ٿռ�
			scanf_s("%d", &k);
			node->data = k;
			last->next = node;//���½ڵ����ӵ�������
			last = node;//ʹ�½ڵ��Ϊ���һ���ڵ�
			node->next = NULL;//������һ���ڵ�
		}

	}
	return(head);
}
void print(LinkList* head)
{
	LinkList* node;
	if (head->next == NULL)//�ж��Ƿ�Ϊ������
		printf("there are nothing in the list.");
	else
	{
		node = head->next;//�ӵ�һ����㿪ʼ���
		do {
			printf("%d\t", node->data);//����ڵ�����
			node = node->next;//�л���һ���ڵ�
		} while (node->next != NULL);//������һ���ڵ����ֹѭ��
		printf("%d\n", node->data);
	}


}
void add(LinkList* head, int num)
{
	LinkList* pre, * node;
	int i = 0,k;
	node = (LinkList*)malloc(sizeof(LinkList));//Ϊ�½ڵ㿪�ٿռ�
	pre = head;
	scanf_s("%d", &k);
	node->data = k;
	for (;i < num;i++) //ȷ������λ��ǰһ���ڵ�
	{
		pre = pre->next;
	}
	node->next = pre->next;//������λ��֮��Ľڵ����ӵ��½ڵ�ĺ���
	pre->next = node;//���½ڵ����ӵ�����λ��ǰһ���ڵ�ĺ���
}
int find_order(LinkList* head, int num) {
	int i = 0;
	LinkList* node = head;
	for (;i < num;i++) //��λ��Ҫ���ҵĽڵ�
	{
		node = node->next;
	}
	return(node->data);//���������ҵ�ֵ
}
void delete(LinkList* head, int num)
{
	LinkList* pre, * cur, * node;
	int i = 0;
	pre = head;
	for (;i < num - 1;i++)
	{
		pre = pre->next;//ȷ����ɾ���ڵ��ǰһ������λ��
	}
	node = pre->next;//�ҵ���ɾ���ڵ��λ��
	cur = node->next;//�ҵ���ɾ���ڵ�ĺ�һ���ڵ��λ��
	pre->next = cur;//����ɾ���Ľڵ���������Ƴ�
	free(node);//�ͷű�ɾ���ڵ���ڴ�

}
int size(LinkList* head)
{
	int i = 0;
	LinkList* node;
	node = head;
	if (node->next == NULL)//�ж��Ƿ�Ϊ������
	{
		return i;//�ǵĻ���ֱ�ӷ���0
	}
	else//���ǵĻ���һ��һ�������ڵ�
	{
		while (1)
		{
			if (node->next != NULL) //
			{
				++i;
				node = node->next;
			}
			else break;//û�нڵ�Ͳ�����
		}
		return (i);
	}
}
void find_data(LinkList* head, int data)
{
	LinkList* node;
	node = head->next;
	int i = 0, k = 0;
	while (node->next != NULL)
	{
		++i;
		if (node->data == data)
		{
			++k;
			break;
		}
		else
		{
			node = node->next;
		}
	}
	if (k == 1)
		printf("�������и�Ԫ��");
	else
		printf("������û�и�Ԫ��");
}
int main()
{
	LinkList* head;
	head = creatList(3);
	printf("The length of list is %d\n", size(head));
	print(head);
	add(head, 3);
	printf("The length of list is %d\n", size(head));
	print(head);
	delete(head, 1);
	printf("The length of list is %d\n", size(head));
	print(head);
	find_data(head, 3);
	return 0;
	
}