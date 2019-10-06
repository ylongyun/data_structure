#include <stdio.h>
#include <LinkList.h>
#include <stdlib.h>
LinkList* creatList(int n)//创建链表
{
	LinkList* head;
	if (n == 0)//n为0的即生成一个空链表
	{
		head = (LinkList*)malloc(sizeof(LinkList));
		head->next = NULL;//封闭节点
		head->data = NULL;

	}
	else
	{
		int i,k;
		LinkList* node, * last;
		head = (LinkList*)malloc(sizeof(LinkList));
		last = head;
		for (i = 0;i < n;i++) {
			node = (LinkList*)malloc(sizeof(LinkList));//为新节点开辟空间
			scanf_s("%d", &k);
			node->data = k;
			last->next = node;//将新节点连接到链表上
			last = node;//使新节点成为最后一个节点
			node->next = NULL;//封闭最后一个节点
		}

	}
	return(head);
}
void print(LinkList* head)//输出链表
{
	LinkList* node;
	if (head->next == NULL)//判断是否为空链表
		printf("there are nothing in the list.");
	else
	{
		node = head->next;//从第一个结点开始输出
		do {
			printf("%d\t", node->data);//输出节点内容
			node = node->next;//切换下一个节点
		} while (node->next != NULL);//输出最后一个节点后终止循环
		printf("%d\n", node->data);//输出最后一个节点
	}


}
void add(LinkList* head, int num)//插入一个节点
{
	LinkList* pre, * node;
	int i = 0,k;
	node = (LinkList*)malloc(sizeof(LinkList));//为新节点开辟空间
	pre = head;
	scanf_s("%d", &k);//输入插入节点的数据
	node->data = k;
	for (;i < num;i++) //找到插入位置前一个节点
	{
		pre = pre->next;
	}
	node->next = pre->next;//将插入位置之后的节点连接到新节点的后面
	pre->next = node;//将新节点连接到插入位置前一个节点的后面
}
int find_order(LinkList* head, int num)//按顺序查找链表内元素
{
	int i = 0;
	LinkList* node = head;
	for (;i < num;i++) //定位所要查找的节点
	{
		node = node->next;
	}
	return(node->data);//返回所查找的值
}
void delete(LinkList* head, int num)//删除一个节点
{
	LinkList* pre, * cur, * node;
	int i = 0;
	pre = head;
	for (;i < num - 1;i++)
	{
		pre = pre->next;//确定被删除节点的前一个结点的位置
	}
	node = pre->next;//找到被删除节点的位置
	cur = node->next;//找到被删除节点的后一个节点的位置
	pre->next = cur;//将被删除的节点从链表中移除
	free(node);//释放被删除节点的内存

}
int size(LinkList* head)//测量链表长度
{
	int i = 0;
	LinkList* node;
	node = head;
	if (node->next == NULL)//判断是否为空链表
	{
		return i;//是的话就直接返回0
	}
	else//不是的话就一个一个的数节点
	{
		while (1)
		{
			if (node->next != NULL) //
			{
				++i;
				node = node->next;
			}
			else break;//没有节点就不数了
		}
		return (i);
	}
}
void find_data(LinkList* head, int data)//按值查找链表内元素
{
	LinkList* node;
	node = head->next;
	int k = 0;//k为查找结果：k=1，找到；k=0，没找到
	while (node->next != NULL)//查找节点
	{
		if (node->data == data)
		{
			++k;
			break;//找到后结束循环
		}
		else
		{
			node = node->next;//没找到继续下一个节点
		}
	}
	if (node->data = data)//查找最后一个节点
		k = 1;
	if (k == 1)
		printf("链表内有该元素");
	else
		printf("链表内没有该元素");
}
LinkList* copy(LinkList* head)//复制链表，返回所复制链表的头指针
{
	LinkList* head_copy, * node, * node_copy,* pre_copy;//pre_copy为当前复制节点的前一个节点
	node = head->next;
	head_copy = creatList(0);//创建复制链表的头节点
	pre_copy = head_copy;
	while (node != NULL)//所有节点复制完后结束循环
	{
		node_copy = (LinkList*)malloc(sizeof(LinkList));//为复制的节点开辟空间
		node_copy->data = node->data;//复制原节点的数据
		pre_copy->next = node_copy;//将复制的节点连接到复制的链表上
		pre_copy = node_copy;//更新前节点
		node_copy->next = NULL;//封闭链表
		node = node->next;//切换下一个要复制的节点
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