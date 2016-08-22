#include<iostream>

using namespace std;

int main()
{
	long long int sum,a,n,i;
	cin >> n;
	sum = 0;
	for(i = 0;i < n; i++)  {
		cin >> a;
		sum = sum + a;
	}
	if( sum == ( n * ( n + 1)) / 2) {
		cout << "YES\n";
	} else {
		cout << "NO\n";
	}
}
