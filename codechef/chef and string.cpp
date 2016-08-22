#include<iostream>

using namespace std;

int main()
{
	int t;
	int n,m;
	char c ;
	cin >> t;
	while(t--) {
		cin >> n;
		if( n % 25 == 0) {
			m = (n / 25) * 26 + (n % 25);
		} else {
			m = (n / 25) * 26 + (n % 25) + 1;
		}
	
		
		while( m  ) {
			c = 'a' +  ( m - 1) % 26;
			cout << c;
			m--;
		}
		cout << "\n";
	}
}
