#include<iostream>

using namespace std;

int main()
{
	int i,j,c,q,t,n,l,r;
	cin >> t;
	while( t-- ) {
		cin >> n >> c >> q;
		for( i = 1; i < q + 1; i++) {
			cin >> l >> r;
			c = l + r - c;
		}
		cout << c << endl;
	}
}
