#include<stdio.h>
#include<string.h>

int main()
{
	char m[100][6],p[2500][6];
	int n,k,l,i,j,s,q,t;
	scanf("%d",&t);
	while(t--) {
		i = j = s = q = 0;
		scanf("%d %d ",&n,&k);
		while( i < n) {
			scanf("%s",m[i]);
			getchar();
			i++;
		}
		while( j < k) {
			scanf("%d",&l);
			while( l--) {
				scanf("%s",p[q]);
				getchar();
				q++;
			}
			j++;
		}
		int flag = 0;
		for( i = 0; i < n; i++) {
			for( j = 0; j < q; j++) {
				if( (s = strcmp(m[i],p[j]) ) == 0) {
					printf("YES ");
					break;
				} 
				if( j == q - 1 && s != 0) {
					printf("NO ");
				}
			}
		}
		printf("\n");
	}
	
	
}
