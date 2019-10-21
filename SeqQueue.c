#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int a[10];
	int front;//��������λ�� 
	int rear;//��β����λ�� 
	int tag;//��־������ȷ�������Ƿ����� 
 } SeqQueue;
void InitQueue(SeqQueue *Q)
{
	Q->tag = Q->front = Q->rear = 0;
 }
void EnterQueue(SeqQueue *Q,int x)
{
	if(Q->tag == 0)
	{
		Q->a[Q->rear] = x;//��� 
		Q->rear = (Q->rear + 1) % 10;//�л���β 
		if(Q->front == Q->rear){//��Ӻ�������Ƿ����� 
			Q->tag = 1;
		}
	 } 
	 else{
	 	printf("������");
	 }
	
}
int OutQueue(SeqQueue *Q)
{
	int x;
	if(Q->tag == 0 && Q->front == Q->rear){
		printf("��Ϊ��");
		return -1;
	}
	
	else
	{
		x = Q->a[Q->front];
		Q->front = (Q->front + 1) % 10;//���¶��� 
	 } 
	 if(Q->front == Q->rear){// ��Ӻ�������Ƿ�Ϊ�� 
	 	Q->tag = 0;
	 }
	 return x;
}
int main()
{
	int *x;
	SeqQueue *Q;
	Q = (SeqQueue*)malloc(sizeof(SeqQueue));
	InitQueue(Q);
	EnterQueue(Q,100);
	printf("%d\n",OutQueue(Q));
	printf("%d,%d",Q->front,Q->rear);
	return 0;
}
