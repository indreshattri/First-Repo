#include<iostream>

using namespace std;

int main()
{
	int i,t,n;
	char c;
	cin >> t;
	while( t--) {
		int a[5] = {0},max = 0;
		cin >> n;
		for( i = 0; i < n; i++) {
			cin >> c;
			if(  c == 'R') {
				a[0]++;
			}
			else if( c == 'G') {
				a[1]++;
			}
			else if( c == 'B') {
				a[2]++;
			}
		}
		for( i = 0; i < 3; i++) {
			if( a[i] > max) {
				max = a[i];
			}
		}
		cout << n -max << "\n";
	}
}
