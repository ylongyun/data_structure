ifndef CORC___STATICLIST_H
#define CORC___STATICLIST_H
#define Maxsize 100
typedef struct Node
{
	int data;//������ 
	struct Node* next;//�α��� 

}component,StaicList[Maxsize];

void reserveArr(component *array);//������������
int mallocArr(component * array);//��ȡ����ռ�
int initArr(component *array);//��ʼ����̬����

#endif //CORC___STATICLIST_H
