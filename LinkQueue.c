#include<stdio.h>
#include <stdlib.h>
typedef struct Node//队列结点 
{
	int data;
	struct Node* next;
}LinkQueueNode;
typedef struct//队列的头部和尾部 
{
	LinkQueueNode* head;
	LinkQueueNode* rear;
}LinkQueue;
void creatQueue(LinkQueue* queue)//初始化队列 
{
	queue->head = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));//为队列头结点开辟空间 
	queue->rear = queue->head;//此时队列没有成员，头部和尾部都指向头节点 
	queue->head->next = NULL;//封闭队列 
}
viod enterQueue(LinkQueue* queue,int data)//入队操作 
{
	LinkQueueNode* node;
	node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));//为新队员开辟空间 
	node->data = data;//新队员的数据 
	queue->rear->next = node;//将新节点插入队列 
	node->next = NULL;//封闭队列 
	queue->rear = node;//更新尾指针 
 } 
 void deleteQueue(LinkQueue* queue,int* data)//出队操作 
 {
 	LinkQueueNode* p;
 	p = queue->head->next;//找到第一个队员的地址 
 	* data = p->data;//取出队员的数据 
 	queue->head->next = p->next;//更新头指针 
 	free(p);//释放出队队员的空间 
 }
