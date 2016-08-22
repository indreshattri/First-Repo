#include<iostream>
#include<stdlib.h>

using namespace std;

int main()
{
	int i,j,n,t,*a,b,c;
	n = 5000;
	a = ( int *)calloc(1, n * sizeof(int));
	for( i = 2; i < n; i++ ) {
		if( a[i] == 0) {
			for( j = i * i; j < n; j = j + i) {
				a[j] = 1;
			}
		}
	}
	cin >> t;
	while( t--) {
		cin >> b >> c;
		for( i = c + b + 1; i < n; i++) {
			if( a[i] == 0) {
				cout << i - c - b << "\n";
				break;
			}
		}
	}
}
