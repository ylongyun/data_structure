#include <stdio.h>
int main(){
	int n,k,i,r,t,l,a[100000],sum,count = 0;
	scanf("%d",&n);
	scanf("%d",&k);
	for(i = 0;i < n;i++){
		scanf("%d",&a[i]);
	}
	for(i = 1; i <= n;i++){
		for(r = 0;r <= (n - i);r++){
			l = r;
			sum = 0;
			for(t = 0;t < i;t++){
				sum += a[l];
				l++;
			}
			if(sum % k == 0){
				count++;
			}
		}
	}
	printf("%d",count);
	return 0;
} 
