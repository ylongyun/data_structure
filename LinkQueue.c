#include<stdio.h>
#include <stdlib.h>
typedef struct Node//���н�� 
{
	int data;
	struct Node* next;
}LinkQueueNode;
typedef struct//���е�ͷ����β�� 
{
	LinkQueueNode* head;
	LinkQueueNode* rear;
}LinkQueue;
void creatQueue(LinkQueue* queue)//��ʼ������ 
{
	queue->head = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));//Ϊ����ͷ��㿪�ٿռ� 
	queue->rear = queue->head;//��ʱ����û�г�Ա��ͷ����β����ָ��ͷ�ڵ� 
	queue->head->next = NULL;//��ն��� 
}
viod enterQueue(LinkQueue* queue,int data)
{
	LinkQueueNode* node;
	node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));
	node->data = data;
	queue->rear->next = node;
	node->next = NULL;
	queue->rear = node;
 } 
 void deleteQueue(LinkQueue* queue,int* data)
 {
 	LinkQueueNode* p;
 	p = queue->head->next;
 	* data = p->data;
 	queue->head->next = p->next;
 	free(p);
 }
