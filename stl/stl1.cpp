#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

int main()
{
	int x;
	int i;
	int n;
	vector<int> vec;
	cin >> n;
	for( i = 0;i<n;i++) {
		cin >> x;
		vec.push_back(x);
	}
	vector<int>:: iterator it1 = vec.begin();
	vector<int>:: iterator it2 = vec.end();
	vector<int>:: iterator it;
	sort(it1,it2);
	for(it = it1; it != it2; it++) {
		cout << *it << " ";
	}
}
