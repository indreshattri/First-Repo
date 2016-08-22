#include<iostream>

using namespace std;

int main()
{
	int t,n,i;
	long long int k,sum;
	long long int max_diff;
	int a[100000],b[100000];
	cin >> t;
	while(t--) {
		cin >> n >> k;
		sum = 0;
		for( i = 0;i < n;i++) {
			cin >> a[i];
		}
		for( i = 0;i < n;i++) {
			cin >> b[i];
		}
		for( i = 0;i < n;i++) {
			if( i == 0) {
				if( b[i] < 0 ) {
					max_diff = -k * b[i];			
				} else {
					max_diff = k * b[i];
				}
			} else {
				if(b[i] < 0 && -1 * k *b[i] > max_diff ) {
					max_diff = -1 *k * b[i];
				}
				if( b[i] >= 0 && 1 * k *b[i] > max_diff) {
					max_diff = 1 * k * b[i] ;
				}
				
			}
			sum = sum + a[i] * b[i];
		}
		cout << sum + max_diff << "\n";
	}
}
