#include <stdio.h>
#include <stdlib.h>
#include<math.h>

/* run this program using the console pauser or add your own getch, system("pause") or input loop */

int main() {
	int n,val=1,i,t,ctr=0,j,b[5];
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%d",&n);
		j=0;
		val=1;
		ctr=0;
		if(n>2048){
				ctr = ctr + n / 2048 ;
				n = n % 2048;
			
				if(n == 0){
					val=n;
					ctr--;
				}
	}
			
		while(val!=n){
			
			if(n/val>=2){
				val=pow(2,j);
				j++;
			}
			
			else{
				ctr++;
				n = n - val;
				val=1;
				j=0;
			}
		}
		b[i]=ctr;
	}
	for(i=0;i<t;i++){
		printf("%d\n",b[i]+1);
	}
	return 0;
}
