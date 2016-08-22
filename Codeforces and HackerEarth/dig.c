#include<stdio.h>
int main()
{
	int i,n,t,j;
	long long unsigned fact;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		fact=1;
		scanf("%d",&n);
	
			for(j=2;j<n+1;j++){
				fact=fact*j;
			}
		printf("%llu\n",fact);
	}
}
	

