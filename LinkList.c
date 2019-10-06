#include <stdio.h>
#include <LinkList.h>
#include <stdlib.h>
LinkList* creatList(int n)//��������
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
void print(LinkList* head)//�������
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
		printf("%d\n", node->data);//������һ���ڵ�
	}


}
void add(LinkList* head, int num)//����һ���ڵ�
{
	LinkList* pre, * node;
	int i = 0,k;
	node = (LinkList*)malloc(sizeof(LinkList));//Ϊ�½ڵ㿪�ٿռ�
	pre = head;
	scanf_s("%d", &k);//�������ڵ������
	node->data = k;
	for (;i < num;i++) //�ҵ�����λ��ǰһ���ڵ�
	{
		pre = pre->next;
	}
	node->next = pre->next;//������λ��֮��Ľڵ����ӵ��½ڵ�ĺ���
	pre->next = node;//���½ڵ����ӵ�����λ��ǰһ���ڵ�ĺ���
}
int find_order(LinkList* head, int num)//��˳�����������Ԫ��
{
	int i = 0;
	LinkList* node = head;
	for (;i < num;i++) //��λ��Ҫ���ҵĽڵ�
	{
		node = node->next;
	}
	return(node->data);//���������ҵ�ֵ
}
void delete(LinkList* head, int num)//ɾ��һ���ڵ�
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
int size(LinkList* head)//����������
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
void find_data(LinkList* head, int data)//��ֵ����������Ԫ��
{
	LinkList* node;
	node = head->next;
	int k = 0;//kΪ���ҽ����k=1���ҵ���k=0��û�ҵ�
	while (node->next != NULL)//���ҽڵ�
	{
		if (node->data == data)
		{
			++k;
			break;//�ҵ������ѭ��
		}
		else
		{
			node = node->next;//û�ҵ�������һ���ڵ�
		}
	}
	if (node->data = data)//�������һ���ڵ�
		k = 1;
	if (k == 1)
		printf("�������и�Ԫ��");
	else
		printf("������û�и�Ԫ��");
}
LinkList* copy(LinkList* head)//�����������������������ͷָ��
{
	LinkList* head_copy, * node, * node_copy,* pre_copy;//pre_copyΪ��ǰ���ƽڵ��ǰһ���ڵ�
	node = head->next;
	head_copy = creatList(0);//�������������ͷ�ڵ�
	pre_copy = head_copy;
	while (node != NULL)//���нڵ㸴��������ѭ��
	{
		node_copy = (LinkList*)malloc(sizeof(LinkList));//Ϊ���ƵĽڵ㿪�ٿռ�
		node_copy->data = node->data;//����ԭ�ڵ������
		pre_copy->next = node_copy;//�����ƵĽڵ����ӵ����Ƶ�������
		pre_copy = node_copy;//����ǰ�ڵ�
		node_copy->next = NULL;//�������
		node = node->next;//�л���һ��Ҫ���ƵĽڵ�
	}
	return(head_copy);
}
int main()
{
	LinkList* head;
	head = creatList(3);
	copy(head);
	print(head);
	print(copy(head));
	return 0;
	
}