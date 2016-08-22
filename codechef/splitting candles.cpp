#include<iostream>

using namespace std;

int main()
{
	unsigned long long int n,k;
	int t;
	cin >> t;
	while( t-- ) {
		cin >> n >> k;
		if ( k != 0)
			cout << n / k << " " << n % k << "\n"; 
		else {
			cout << "0" << " " << n << "\n";
		}
	}
}
