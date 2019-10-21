#include <stdio.h>
#include <stdlib.h>
typedef struct
{
	int a[10];
	int front;//队首所在位置 
	int rear;//队尾所在位置 
	int tag;//标志变量，确定队列是否满队 
 } SeqQueue;
void InitQueue(SeqQueue *Q)
{
	Q->tag = Q->front = Q->rear = 0;
 }
void EnterQueue(SeqQueue *Q,int x)
{
	if(Q->tag == 0)
	{
		Q->a[Q->rear] = x;//入队 
		Q->rear = (Q->rear + 1) % 10;//切换队尾 
		if(Q->front == Q->rear){//入队后检查队列是否满队 
			Q->tag = 1;
		}
	 } 
	 else{
	 	printf("队已满");
	 }
	
}
int OutQueue(SeqQueue *Q)
{
	int x;
	if(Q->tag == 0 && Q->front == Q->rear){
		printf("队为空");
		return -1;
	}
	
	else
	{
		x = Q->a[Q->front];
		Q->front = (Q->front + 1) % 10;//更新队首 
	 } 
	 if(Q->front == Q->rear){// 入队后检查队列是否为空 
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
