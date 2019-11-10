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
		}
		printf("%d\n",c[k - 1]);
	}
	else{
		printf("输入的数据有误\n");
	}
}
