#include<stdio.h>
#include <stdlib.h>
typedef struct Stack
{
	int data[100];
	int top;
}LinkStack;
LinkStack *initStack(LinkStack *stack)//��ʼ��ջ 
{
	stack->top = -1;
	return stack;
}
void enterStack(LinkStack *stack)//��ջ���� 
{
	if(stack->top+1>99)
		printf("ջ����");
	else
	{
		stack->top++;//ջ������ 
		scanf("%d",&stack->data[stack->top]);//�����³�ԱԪ�� 
	} 
}
int outStack(LinkStack *stack)//��ջ���� 
{
	if(stack->top == -1)
	{
		printf("ջΪ��");
		return -1;
	}
	else
	{
		stack->top--;//ջ��ǰ��
		return stack->data[stack->top+1];//�����³�ԱԪ�� 
	 } 
}
int main()
{
	LinkStack *stack;
	int i;
	stack = (LinkStack *)malloc(sizeof(LinkStack));
	for(i=0;i<=5;i++){
		enterStack(stack);
	}
	for(i=0;i<=5;i++){
		printf("%d\t",outStack(stack));
	}
	return 0;
}

