/*	��������
 
�������룺
3 10
���������
  120
���ݹ�ģ��Լ��:
����������ÿһ�����ķ�Χ��
�������������int��ʾʱ���������*/ 
#include <stdio.h>

int main(){
	int fun(int k,int n);
	int k,n;
	scanf("%d%d",&k,&n);
	printf("%d",fun(k,n));
	return 0;
}
int fun(int k,int n){
	if(k == 0 || k == n){
		return 1;
	}
	else{
		return (fun(k,n-1)+fun(k-1,n-1));
	}
}

