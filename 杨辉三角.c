#include "stdio.h"
void main() 
{
	int i,j,n,k;
	scanf("%d",&n);
	for(i=1;i<=n;i++)
	{
		k=1;
		for(j=1;j<i;j++)
		{
			printf("%4d",k);
			k=k*(i-j)/j;
		}
		printf("   1\n");
	}
}
