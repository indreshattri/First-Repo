#include<stdio.h>
int main()
{
	int i,diff,t,n,m,k,grtr,l;
	scanf("%d",&t);
	for(i = 0; i < t; i++ ) {
		scanf("%d %d %d",&n,&m,&k);
		if (n > m) {
			grtr = n;
			l = m;
		}
		else{
			grtr = m;
			l = n;
		}
		if( grtr - l > k ) {
			diff = grtr - l - k;
		}
		else {
			diff = 0;
		}
		printf("%d\n",diff);
	}
}
