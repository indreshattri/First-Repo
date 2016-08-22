#include<stdio.h>
#include<stdlib.h>
int main()
{
	int t,n,i,x;
	char s1[20],s2[20],s3[20];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%s + %s = %s",s1,s2,s3);
		if(s1[0] == '?'){
			x = atoi(s2);
			n = atoi(s3);
			printf("%d\n",n-x);
		}
		if(s2[0] == '?'){
			x = atoi(s1);
			n = atoi(s3);
			printf("%d\n",n-x);
		}
		if(s3[0] == '?'){
			x = atoi(s1);
			n = atoi(s2);
			printf("%ld\n",n+x);
		}
	}
}
