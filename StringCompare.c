#include <stdio.h>
int main(){
	int StringCompare(char *a,char *b);
	char a[10]={"asfafekefa"},b[4]={"feke"};
	printf("%d\n",StringCompare(a,b));
}
int StringCompare(char *a,char *b){
	int i,j,k = 0;
	i = j = k;
	while(i < (sizeof(a) / sizeof(a[0])) && j < (sizeof(b) / sizeof(b[0]))){
			if(a[i] == b[j]){
			i++;
			j++;
		}
		else{
			k++;
			i = k;
			j = 0;
		}
	}
	return k;
	
}
