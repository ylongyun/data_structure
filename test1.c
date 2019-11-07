/*
　输入一个实数x，求最小的n使得，1/2+1/3+1/4+...+1/(n+1)>=x。

　　输入的实数x保证大于等于0.01，小于等于5.20，并且恰好有两位小数。你的程序要能够处理多组
数据，即不停地读入x，如果x不等于0.00，则计算答案，否则退出程序。

　　输出格式为对于一个x，输出一行n card(s)。其中n表示要计算的答案。
输入格式
　　分行输入x的具体数值
输出格式
　　分行输出n的数值，格式为n card(s)
样例输入
1.00
3.71
0.04
5.19
0.00

样例输出
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


