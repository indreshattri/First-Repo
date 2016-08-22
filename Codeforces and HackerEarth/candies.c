#include<stdio.h>
int main()
{
	int i;
	int j;
	int t;
	int n;
	int ctr;
	long unsigned int a[10000];
	double mean;
	int sum;
	double temp;
	int flag = 0;
	scanf("%d",&t);
	for(i = 0; i < t; i++) {
		scanf("%d",&n);
		mean = 0;
		ctr = 0;
		flag = 0;
		for(j = 0; j < n; j++){
			scanf("%lu",&a[j]);
			if( j == 0) {
				mean = a[j];
			} else {
				mean = (mean * (j - 1) + a[j] ) / j;
			}
		}
		printf("%f\n",mean);
		temp  = mean * n;
		sum = mean;
		if( (float) sum == mean && (int)temp%n == 0) {
			flag = 1;
			for( j = 0; j < n; j++) {
				if( a[j] < (int)mean) {
					ctr =  ctr + (int)mean - a[j];
				}
			}
		}
		if(flag == 1){
			printf("%d\n",ctr);
		} else {
			printf("-1\n");
		}
	}
	return 1;
}
