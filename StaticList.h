ifndef CORC___STATICLIST_H
#define CORC___STATICLIST_H
#define Maxsize 100
typedef struct Node
{
	int data;//数据域 
	struct Node* next;//游标域 

}component,StaicList[Maxsize];

void reserveArr(component *array);//创建备用链表
int mallocArr(component * array);//提取分配空间
int initArr(component *array);//初始化静态链表

#endif //CORC___STATICLIST_H
