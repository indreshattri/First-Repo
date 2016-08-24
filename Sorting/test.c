#include<stdio.h>

void func(int a[], int n ,int indx , int  *rslt)
{
	if( n < 1){
		return ;
	}
	if( n == 1 ) {
		* rslt = * rslt + a[indx];
		return ;
	}
	if( n == 2) {
		*rslt = * rslt + a[indx] + a[indx + 1];
		return;
	}
	if( n > 2) {
		*rslt = *rslt * a[indx] * a[indx + 1] * a[indx + 2];
		func(a,n-3,indx + 3,&(*rslt));
		return ;
	}
}

int main()
{
	int i;
	int n;
	int a[100];
	int rslt = 0;
	scanf("%d", &n);
	if(n > 2) {
		rslt = 1;
	}
	for(i = 0; i < n; i++ ) {
		scanf( "%d", &a[i] );
	}
	func(a,n,0,&rslt);
	printf("%d\n",rslt);
}
