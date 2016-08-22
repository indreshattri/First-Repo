#include<iostream>
#include<string>
#include<stdlib.h>

using namespace std;

int main() 
{
	long long int i,m,ctr1,ctr2,ctr3,ctr4,ctr,t,l,j;
	string a;
	cin >> t;
	while( t-- ) {
		cin >> a;
		l = a.length();
		i = 0;
		m = l/2;  
		ctr4 = ctr3 = ctr2 = ctr1 = ctr = 0;
		if( l % 2 == 0) {
			while( i < m) {
				if( a[i] != a[m + i]) {
					ctr = ctr4 = ctr3 = ctr2 = ctr1 = 5;
					break;
				}
				i++;
			}
		}
		if( l %2 != 0 && l < 5) {
				if ( l == 3) {
					if( ( a[0] == a[1] || a[1] == a[2] || a[0] == a[2])) {
						ctr = ctr1 = ctr2 = ctr3 = ctr4 = 0;
					} else {
						ctr = ctr1 = ctr2 = ctr3 = ctr4 = 5;
					} 
					
				}
				if( l == 1) {
					ctr = ctr1 = ctr2 = ctr3 = ctr4 = 0;
				}
		}
		if( l % 2 != 0 && l > 4) {
			ctr = 5;
			while( i < m ) {
				if( a[i] != a[m + i]) {
					if( i == m - 1 && l > 4) {
						ctr1 = ctr2 = 4;
						break;
					}
					j = i + 1;
					while( j < m ) {
						if( a[j] != a[m + j - 1]) {
							ctr1 = 5;
							break;
						}
						j++;
					}	
					j = i + 1;
					while( j < m ) {
						if( a[j - 1] != a[m + j]) {
							ctr2 = 5;
							break;
						}
						j++;
					}
					i = m + 1;
				}
				i++;
			}
			i = 0;
			m++;
			while( i < m ) {
				if( a[i] != a[m + i]) {
					if( i == m - 1 && l > 4) {
						ctr3 = ctr4 = 4;
						break;
					}
					j = i + 1;
					while( j < m) {
						if( a[j] != a[m + j - 1]) {
							ctr3 = 5;
							break;
						}
						j++;
					}	
					j = i + 1;
					while( j < m ) {
						if( a[j - 1] != a[m + j]) {
							ctr4 = 5;
							j = m - 1;
							break;
						}
						j++;
					}
					i = m + 1;
				}
				i++;
			}
		}
		if( ctr1 != 5 || ctr2 != 5 || ctr3 != 5 || ctr4 != 5 || ctr != 5) {
			cout <<"YES\n";
		} else {
			cout << "NO\n";
		}
	}
}
