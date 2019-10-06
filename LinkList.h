#ifndef CORC___LINKLIST_H
#define CORC___LINKLIST_H

typedef struct Node
{
	int data;//数据元素
	struct Node* next;//下一个结点的地址

}LinkList;

LinkList* creatList(int n);//创建链表
int find_order(LinkList* head, int num);//按顺序查找链表内元素
void add(LinkList* head, int num);//插入一个节点
void delete(LinkList* head, int num);//删除一个节点
void print(LinkList* head);//输出链表
int size(LinkList* head);//测量链表长度
void finf_data(LinkList* head,int num);//按值查找链表内元素
LinkList* copy(LinkList* head)//复制链表，返回所复制链表的头指针

#endif //CORC___LINKLIST_H