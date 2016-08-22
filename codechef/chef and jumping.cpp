#include<iostream>

using namespace std;

int main()
{
	unsigned long long int d;
	cin >> d;
	if( d % 3 == 0 || d % 6 == 1 ) {
		cout << "yes\n";
	} else {
		cout << "no\n";
	}
}
