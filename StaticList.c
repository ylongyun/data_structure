#include <stdio.h> 
#include <StaticList.h> 
void reserveArr(component *array)//������������
{
    for (int i=0; i<maxSize; i++) {
        array[i].cur=i+1;//��ÿ������������ӵ�һ��
    }
    array[maxSize-1].cur=0;//�������һ�������α�ֵΪ0
}
int mallocArr(component * array)//��ȡ����ռ�
{
    //����������ǿգ��򷵻ط���Ľ���±꣬���򷵻�0�����������һ�����ʱ���ý����α�ֵΪ0��
    int i=array[0].cur;
    if (array[0].cur) {
        array[0].cur=array[i].cur;
    }
    return i;
}
int initArr(component *array)//��ʼ����̬����
{
    reserveArr(array);//���ӱ�������
    //�ӱ����������ó�һ��������Ϊ�����ͷ��㣬���ص�������������±�
    int body=mallocArr(array);
    //����һ��������������ָ��ʹ��ָ�����������һ����㣬��Ϊ����Ϊ�գ����Ժ�ͷ����غ�
    int tempBody=body;
    for (int i=1; i<5; i++) 
	{
        int j=mallocArr(array);//�ӱ����������ó����еķ���
        array[tempBody].cur=j;//������Ŀ��߷�����������������һ��������
        array[j].data='a'+i-1;//��������ķ������������ʼ��
        tempBody=j;//��ָ���������һ������ָ�����
    }
    array[tempBody].cur=0;//�µ��������һ������ָ������Ϊ0
    return body;
}
