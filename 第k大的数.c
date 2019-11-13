/* 
问题描述
给定一个序列，每次询问序列中第l个数到第r个数中第K大的数是哪个。
输入格式
第一行包含一个数n，表示序列长度。
第二行包含n个正整数，表示给定的序列。
第三个包含一个正整数m，表示询问个数。
接下来m行，每行三个数l,r,K，表示询问序列从左往右第l个数到第r个数中，从大往小第K大的数是哪个。序列元素从1开始标号。
输出格式
总共输出m行，每行一个数，表示询问的答案。 
样例输入
5
1 2 3 4 5
2
1 5 2
2 3 2 
样例输出
4
2 
数据规模与约定
对于30%的数据，n,m<=100；
对于100%的数据，n,m<=1000；
保证k<=(r-l+1)，序列中的数<=106。

*/ 
#include <stdio.h>
int main(){
	void fun(int l,int r,int k,int a[]);
	int i,a[100],n,m,b[300];
	scanf("%d",&n);
	for(i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	scanf("%d",&m);
	for(i = 0;i < (3 * m);i++){
		scanf("%d",&b[i]);
	}
	for(i = 0;i < (3 * m);i += 3){
		fun(b[i],b[i+1],b[i+2],a);
	}
} 
void fun(int l,int r,int k,int *a){
	int c[100],i,d,n,m,t;
	d = r - l + 1;
	if(k <= d){
		for(i = 0;i < d;i++){
			c[i] = a[i + l - 1];
		}
		for(i = 0;i < k;i++){
			n = i;
			for(m = i + 1;m < d;m++){
				if(c[i] < c[m])
				n = m;
			}
			if(i != n){
				t = c[i];
				c[i] = c[n];
				c[n] = t;
			}

