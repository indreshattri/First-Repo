#include<stdio.h>
#include<stdlib.h>

int main()
{
	int g[50][50],x,i,j,k,n,max = 0;
	scanf("%d",&n);
	for( i = 0; i < n; i++) {
		for( j = 0; j < n; j++) {
			scanf("%d",&x);
			if( i == j) {
				g[i][j] = 0;
			}
			else if( x == 0) {
				g[i][j] = 1000 ;
			} else {
				g[i][j] = 1;
			}
		}
	}
	for( i = 0 ; i < n; i++) {
		for( j = 0; j < n; j++) {
			printf("%d ",g[i][j]);
		}
		printf("\n");
	}
	printf("\n");
	for( k = 0; k < n; k++) {
		for( i = 0; i < n; i++) {
			for( j = 0; j < n; j++) {
				if( g[i][j] > g[i][k] + g[k][j]) {
					g[i][j] = g[i][k] + g[k][j];
				}
				if( k == n -1 && max < g[i][j]) {
					max = g[i][j];
				}
				printf("%d ",g[i][j]);
			}
			printf("\n");
		}
		printf("\n");
	}
	printf("%d",max);
}
