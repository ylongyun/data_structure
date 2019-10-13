#include<stdio.h>
#include <stdlib.h>
typedef struct Stack
{
	int data[100];
	int top;
}LinkStack;
LinkStack *initStack(LinkStack *stack)//初始化栈 
{
	stack->top = -1;
	return stack;
}
void enterStack(LinkStack *stack)//入栈操作 
{
	if(stack->top+1>99)
		printf("栈已满");
	else
	{
		stack->top++;//栈顶后移 
		scanf("%d",&stack->data[stack->top]);//输入新成员元素 
	} 
}
int outStack(LinkStack *stack)//出栈操作 
{
	if(stack->top == -1)
	{
		printf("栈为空");
		return -1;
	}
	else
	{
		stack->top--;//栈顶前移
		return stack->data[stack->top+1];//返回新成员元素 
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

