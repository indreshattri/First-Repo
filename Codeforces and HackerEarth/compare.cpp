#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int main()
{
	int i,j,t,n,m,l1,l2;
	char *a,*b;
	scanf("%d",&t);
	for( i=0 ;i<t;i++) {
		j = 0;
		b = (char *)malloc(1000000 * sizeof(char));
		a = (char *)malloc(1000000 * sizeof(char));
		scanf("%s%s",a,b);
		for(j = 0;a[j] =='0';j++) {
		}
		n = j;
		for(j = 0;b[j] =='0';j++) {
			
		}
		m = j;
		l1 = strlen(a + n );
		l2 = strlen( b + m );
		if( l1 > l2) {
			printf(">\n");
		}
		if(l1 < l2) {
			printf("<\n");
		}
		if( l1 == l2  ) { 
			if ( l1 == l2 && l1 == 0 ) {
				printf("=\n");
			} else {
				for( j = 0; j < l1; j++) {
					if( a[ n + j ] > b[ m + j ] ) {
						printf(">\n");
						break;
					}
					if( a[ n + j ] < b[ m + j ] ) {
						printf("<\n");
						break;
					}
					if( j == l1 - 1 && a[ n + j ] == b[ m + j ] ) {
						printf("=\n");
					}
				}
			}
		}
		free(a);
		free(b);
	}
}
