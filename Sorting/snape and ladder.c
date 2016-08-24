#include <stdio.h>
#include <stdlib.h>
#include<math.h>>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int i,t;
	float a[10000][2],ls,b;

	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%f %f",&b,&ls);
		a[i][0]=sqrt( (ls * ls) - (b * b) );
		a[i][1]=sqrt( (ls * ls) + (b * b) );
	}
	for(i=0;i<t;i++){
		printf("%f %f\n",a[i][0],a[i][1]);
	}
	return 0;
}
