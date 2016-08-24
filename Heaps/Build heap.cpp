#include<stdio.h>

int left(int i) 
{
	return 2 * i  + 1;
}

int right ( int i ) 
{
	return 2 * i + 2;
}

int parent( int i ) 
{
	return i / 2;
}

void print( int * a,int i,int n)
{
	int l;
	int r;
	l = left(i);
	r = right(i);
	
	if( l + 1 <= n ) {
		print(a,l,n);
	}
	
	if( r + 1 <= n) {
		print(a,r,n);
	}
	printf( "%d  ",a[i]);
}

void max_heapify( int * a,int i,int n)
{
	if( i + 1 > n/ 2) {
		return;
	}
	int l;
	int r;
	int max;
	int temp;
	l = left( i );
	r = right( i );
	max = i;
	if( a[l ] > a[i]  && l < n ) {
		max = l;
	}
	if( a[r] > a[max ] && r < n ) {
		max = r;
	}
	if( max != i ) {
		temp = a[i ];
		a[i ] = a[max];
		a[max] = temp;
		return max_heapify(a,max,n);
	} 
}

void restoreup( int * a, int x,int n)
{
	a[n - 1] = x;
	int par = (n - 1) / 2;
	int i = n - 1;
	while( par >= 0 && a[par] < x) {
		a[i] = a[par];
		i = par;
		par = i/2;
	}
	a[i] = x;
}

void heapsort( int * a,int n)
{
	int i;
	int j;
	int temp;
	for( i = n - 1; i >=0; i-- ) {
		temp = a[i];
		a[i] = a[0];
		a[0] = temp;
		max_heapify(a,0,i );
		for( j = 0 ; j < n; j++) {
			printf("%d ",a[j]);
		}
		printf("\n");
	}
}

int main()
{
	int n,i,a[100],q,x;
	scanf("%d %d",&n,&q);
	for( i = 0; i < n ; i++) {
		scanf("%d",&a[i]);
	}
	for(i = n / 2 - 1; i >=0; i--) {
		max_heapify(a,i,n);
	}
	for( i = 0 ; i < n; i++) {
		printf("%d ",a[i]);
	}
	printf("\n");
	for( i = 0; i < q; i++) {
		scanf("%d",&x);
		n++;
		restoreup(a,x,n);
	}
	for( i = 0 ; i < n; i++) {
		printf("%d ",a[i]);
	}
	
}
