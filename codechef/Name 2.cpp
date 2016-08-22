#include<iostream>
using namespace std;

int subsq( string s1, string s2)
{
	int i = 0,j = 0,flag = 0;
	while( s1[i] != '\0') {
		while( s2[j] != '\0') {
			if(s1[i] == s2[j] ) {
				j++;
				flag = 1;
				break;
			}
			j++;
			flag = 0;
		}
		if( flag == 1) {
			i++;
		}
		if(  s1[i] == '\0') {
			return 1;
		} 
		if( s2[j] == '\0' && s1[i] != '\0') {
			return 0;
		}
	}
}

int main()
{
	int t,a;
	string s1,s2;
	cin >> t;
	while( t-- ) {
		cin >> s1 >> s2;
		a = subsq(s1,s2);
		if( a == 0) {
 			a = subsq(s2,s1);
		}
		if( a == 1 ) {
			cout << "YES\n";
		} else{
			cout << "NO\n";
		}
	}
}
