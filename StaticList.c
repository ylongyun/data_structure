#include <stdio.h> 
#include <StaticList.h> 
void reserveArr(component *array)//创建备用链表
{
    for (int i=0; i<maxSize; i++) {
        array[i].cur=i+1;//将每个数组分量链接到一起
    }
    array[maxSize-1].cur=0;//链表最后一个结点的游标值为0
}
int mallocArr(component * array)//提取分配空间
{
    //若备用链表非空，则返回分配的结点下标，否则返回0（当分配最后一个结点时，该结点的游标值为0）
    int i=array[0].cur;
    if (array[0].cur) {
        array[0].cur=array[i].cur;
    }
    return i;
}
int initArr(component *array)//初始化静态链表
{
    reserveArr(array);//链接备用链表
    //从备用链表中拿出一个分量作为链表的头结点，返回的是这个分量的下标
    int body=mallocArr(array);
    //声明一个变量，把它当指针使，指向链表的最后的一个结点，因为链表为空，所以和头结点重合
    int tempBody=body;
    for (int i=1; i<5; i++) 
	{
        int j=mallocArr(array);//从备用链表中拿出空闲的分量
        array[tempBody].cur=j;//将申请的空线分量链接在链表的最后一个结点后面
        array[j].data='a'+i-1;//给新申请的分量的数据域初始化
        tempBody=j;//将指向链表最后一个结点的指针后移
    }
    array[tempBody].cur=0;//新的链表最后一个结点的指针设置为0
    return body;
}
