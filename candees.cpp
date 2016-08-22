#include<stdio.h>
int main()
{
	long long int i;
	int j;
	long long int t;
	long long int n;
	long long int ctr;
	long long int a[10000];
	long long mean;
	scanf("%d",&t);
	for(i = 0; i < t; i++) {
		scanf("%d",&n);
		mean = 0;
		ctr = 0;
		for(j = 0; j < n; j++){
			scanf("%lld",&a[j]);
			mean=mean+a[j];
		}
		if( mean%n==0 ) {
			mean=mean/n;
			for( j=0; j<n; j++ ) {
				if( a[j]<mean ) {
					ctr=ctr+mean-a[j];
				}
			}
			printf("%lld\n", ctr);
		} else {
			printf("-1\n");
		}
	}
	return 0;
}
