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
viod enterQueue(LinkQueue* queue,int data)//��Ӳ��� 
{
	LinkQueueNode* node;
	node = (LinkQueueNode*)malloc(sizeof(LinkQueueNode));//Ϊ�¶�Ա���ٿռ� 
	node->data = data;//�¶�Ա������ 
	queue->rear->next = node;//���½ڵ������� 
	node->next = NULL;//��ն��� 
	queue->rear = node;//����βָ�� 
 } 
 void deleteQueue(LinkQueue* queue,int* data)//���Ӳ��� 
 {
 	LinkQueueNode* p;
 	p = queue->head->next;//�ҵ���һ����Ա�ĵ�ַ 
 	* data = p->data;//ȡ����Ա������ 
 	queue->head->next = p->next;//����ͷָ�� 
 	free(p);//�ͷų��Ӷ�Ա�Ŀռ� 
 }
