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
