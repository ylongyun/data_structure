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
