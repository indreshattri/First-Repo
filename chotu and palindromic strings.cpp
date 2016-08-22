#include<iostream>
#include<string>
 using namespace std;
 
 int check (string s ) {
 	int n,i;
 	n = s.size();
 	for(i = 0; i < n / 2; i++) {
 		if( s[i] != s[n - 1 - i] ) {
 			return 0;
		 }
	 }
	 return 1;
 }
 
 int main()
 {
 	int t;
 	cin >> t ;
 	while(t--) {
 		string s1, s2, s3, s4;
 		cin >> s1 >>  s2;
 		s3 = s1 + s2;
 		s4 = s2 + s1;
 		if( check(s3) == 1 || check(s4) == 1) {
 			cout << "YES\n";
		 } else {
		 	cout <<  "NO\n";
		 }
	 }
 }
