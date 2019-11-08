/*	问题描述
 
样例输入：
3 10
样例输出：
  120
数据规模和约定:
输入数据中每一个数的范围。
　　例：结果在int表示时不会溢出。*/ 
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

