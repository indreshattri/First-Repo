#include<iostream>
#include<string>
using namespace std;

int main()
{
	int t,i,n,flag;
	string s;
	cin >> t;
	while(t--) {
		cin >> s;
		n = s.size();
		flag = 0;
		for(i = 0 ; i < n - 2; i++) {
			if( s[i] == '0') {
					if(s[i + 1] == '1' && s[i + 2] == '0') {
						flag = 1;
						break;
					}
			}
			if( s[i] == '1') {
					if(s[i + 1] == '0' && s[i + 2] == '0') {
						flag = 1;
						break;
					}
			}
		}
		if ( flag == 1) {
			cout << "Good\n";
		} else {
			cout << "Bad\n";
		}
	}
}
