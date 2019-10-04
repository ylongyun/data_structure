#ifndef CORC___LINKLIST_H
#define CORC___LINKLIST_H

typedef struct Node
{
	int data;//ÄÚÈÝ
	struct Node* next;//ÏÂÒ»¸ö½ÚµãµÄµØÖ·

}LinkList;

LinkList* creatList(int n);//
int find_data(LinkList* list, int num);//
void add(LinkList* head, int num);//
void delete(LinkList* head, int num);//
void print(LinkList* list);
int size(LinkList* head);

#endif //CORC___LINKLIST_H
