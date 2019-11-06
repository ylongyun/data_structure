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


