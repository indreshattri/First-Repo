#include<iostream>

using namespace std;

int main()
{
	int t,n,dig,m;
	cin >> t;
	while(t--) {
		cin >> n;
		m = n;
		if ( n % 7 == 0 ) {
			dig =  n;
		} else {
			while( n % 7 != 0 && n > 0) {
				n = n - 4;
			}
			if ( n % 7 == 0) {
				dig = n;
			} else {
				dig = -1;
			}
		}
		cout << dig << "\n";
	}
}
