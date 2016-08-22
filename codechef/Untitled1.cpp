#include<iostream>
#include<stdlib.h>

using namespace std;
	
int main()
{
	int i,n,m,t;
	string s;
	int *a;
	cin >> t;
	while(t--) {
		cin >>n;
		a = (int *)calloc(n , sizeof(int));
		cin >> s;
		m = 0;
		for( i = 0; i < n; i++) {
			if( i == 0 && s[0] == '1') {
				a[0] = 1;
				a[1] = 1;
			}
			else if( i < n - 1 && s[i] == '1') {
				a[i] = a[i - 1] = a[i + 1] = 1;
			} else if( i == n - 1 && s[i] == '1' ) {
				a[i] = a[i - 1] = 1;
			}
		}
		for( i = 0; i < n; i++) {
			if(a[i] == 1) {
				m++;
			}
		}
		cout <<n - m << "\n";
		free(a);
	}
	
}
