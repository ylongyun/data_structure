/*
������һ��ʵ��x������С��nʹ�ã�1/2+1/3+1/4+...+1/(n+1)>=x��

���������ʵ��x��֤���ڵ���0.01��С�ڵ���5.20������ǡ������λС������ĳ���Ҫ�ܹ��������
���ݣ�����ͣ�ض���x�����x������0.00�������𰸣������˳�����

���������ʽΪ����һ��x�����һ��n card(s)������n��ʾҪ����Ĵ𰸡�
�����ʽ
������������x�ľ�����ֵ
�����ʽ
�����������n����ֵ����ʽΪn card(s)
��������
1.00
3.71
0.04
5.19
0.00

�������
3 card(s)
61 card(s)
1 card(s)
273 card(s)
 


*/ 
#include <stdio.h>
int main(){
	void fun(double x);
	int i = 0,k = 0;
	float x = 0,a[1000] = {0};
	
	while(1){
		scanf("%f",&x);
		if(x == 0){
			break;
		}
		a[i] = x;
		++i;
	}
	for(k = 0;k < i;k++){
		fun(a[k]);
	}
	return 0;
}
void fun(double x){
	int n;
	double sum;
		for(n = 1,sum = 0;;n++){
			sum = sum + 1.00 / (double)(n + 1);
			if(sum >= x){
				printf("%d card(s)\n",n);
				break;
			}
		}
}


