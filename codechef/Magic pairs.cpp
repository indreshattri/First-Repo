#include<iostream>

using namespace std;

int main()
{
	long long int x,n,i,ctr,t;
	cin >> t;
	while( t--) {
		cin >> n;
		ctr = 0;
		for( i = 0; i < n; i++) {
			cin >> x;
			if( x > 0 && x <= n) {
				ctr++;
			}
		}
		cout << ( ctr * ( ctr - 1)) / 2 << "\n";
	}
}
