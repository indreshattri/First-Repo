#include<iostream>

using namespace std;

int main()
{
	int t;
	string s;
	string m;
	int n;
	int i;
	cin >> t >> m;
	while(t--) {
		cin >> s;
		i = 0;
		while( s[i] != '\0') {
			if( s[i] > 64 && s[i] < 91) {
				n = s[i] - 65;
				s[i] = m[n] - 32;
			}
			if( s[i] > 96 && s[i] < 123) {
				n = s[i] - 97;
				s[i] = m[n];
			}
			if( s[i] == '_') {
				s[i] = ' ';
			}
			i++;
		}
		cout << s << "\n";
	}
	
}
