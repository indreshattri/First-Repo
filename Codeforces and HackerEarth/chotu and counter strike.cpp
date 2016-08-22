#include<iostream>
#include<map>

using namespace std;

int main()
{
	int t,n,m,max1 = 0,max2 = 0;
	string s1,dump,s2;
	map<string,int>mp1,mp2;
	
	cin >> t;
	while( t-- ) {
		cin >> n;
		max1 = 0;
		max2 = 0;
		while(n--) {
			cin >> s1 >> dump >> s2;
			mp1[s1] = mp1[s1] + 1;
			mp2[s2] = mp2[s2] + 1;
		}
		map<string,int>:: iterator it;
		for( it = mp1.begin(); it != mp1.end(); it++ ) {
			if( it->second > max1) {
				max1 = it->second;
			}
		}
		for( it = mp2.begin(); it != mp2.end(); it++ ) {
			if( it->second > max2) {
				max2 = it->second;
			}
		}
		for( it = mp1.begin(); it != mp1.end(); it++ ) {
			if( it->second == max1) {
				cout << it->first << " " ;
				break;
			}
		}
		for( it = mp2.begin(); it != mp2.end(); it++ ) {
			if( it->second == max2) {
				cout << it->first ;
				break;
			}
		}
		cout << "\n";
		mp1.clear();
		mp2.clear();
	}
}

