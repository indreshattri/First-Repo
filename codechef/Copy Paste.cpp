#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	int * a,t,x,n,max ,i,ctr;
	cin >> t;
	while( t--) {
		cin >> n;
		a = ( int *)calloc( 1, 100005 * sizeof( int ));
		max = ctr = 0;
		for( i = 0; i < n; i++) {
			cin >> x;
			a[x]++;
			if( x > max) {
				max  = x;
			}
		}
		for( i = 0; i < max + 1; i++) {
			if( a[i] > 0) {
				ctr++;
			}
		}
		cout << ctr << "\n";
	}
}
