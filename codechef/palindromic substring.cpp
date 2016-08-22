#include<iostream>

using namespace std;

int main()
{
	int i,j,n,flag,t;
	string s1,s2,a,b;
	cin >> t;
	while(t--) {
		flag = 0;
		i = 0;
		cin >> a >> b;
		while( a[i] != '\0') {
			j = 0;
			while( b[j] != '\0') {
				if( a[i] == b[j]) {
					flag = 1;
					break;
				}
				j++;
			}
			if( flag == 1) {
				break;
			}
			i++;
		}
		if( flag == 1)  {
			cout << "Yes\n";
		} else {
			cout << "No\n";
		}
		
	}
}
