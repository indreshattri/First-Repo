#include<stdio.h>
#include<math.h>
int main()
{
	long unsigned int a[100000],b[100000];
	int t,i,j=0;
	scanf("%d",&t);
	for(i=0;i<t;i++){
		scanf("%lu",&a[i]);
	}
	for(i=0;i<t;i++){
		b[i]=0;
		j=0;
		while(a[i]/pow(5,j+1)>0){
			b[i]=b[i] + a[i]/pow(5,j+1);
			j++;
		}
	}
	for(i=0;i<t;i++){
		printf("%lu\n",b[i]);
	}
	return 0;
}
