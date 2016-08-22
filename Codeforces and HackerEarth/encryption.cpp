#include<stdio.h>
#include<stdlib.h>
int main()
{
	int i,j=0,t,key,m;
	char *s;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&key);
		j = 0;
		s = (char *)malloc(1000000 * sizeof(char));
		scanf("%s",s);
		if(key < 26) {
			while( s[j] !='\0') {
				if ( s[j] == '.'){
					s[j] = ' ';
				} else if( s[j] > 96 ){
					m = (s[j] + key - 96) % 26;
					if( m == 0 ) {
						s[j] = 'z';
					} else {
						s[j] = 96 + m;
					}
				} else if( s[j] < 96) {
				m = (s[j] + key - 64) % 26;
					if( m == 0) {
							s[j] = 'Z';
					
					} else{
						s[j] = 64 + m;
					}
				}
				j++;
			}
			printf("%s\n",s);
		}
		if( key > 25) {
			key = key - 26;
			while( s[j] !='\0') {
				if ( s[j] == '.'){
					s[j] = ' ';
				} else if( s[j] > 96){
					m = (s[j] + key - 96) % 26;
					if( m == 0 ) {
						s[j] = 'Z';
					}else {
						s[j] = 64 + m;
					}
				} else if( s[j] < 96 ) {
				m = (s[j] + key - 64) % 26;
					if( m == 0 ) {
						s[j] = 'z';
					} else {
						s[j] = 96 + m;
					}
				}
				j++;
			}
			printf("%s\n",s);
		}
		free(s);
		
	}
	return 0;
}
