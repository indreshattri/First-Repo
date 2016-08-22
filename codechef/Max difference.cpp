#include<iostream>
#include<stdlib.h>

using namespace std;

void merge(int * a,int * b,int * c,int n,int m)
{
	int i,j,k;
	i = j = k = 0;
	while( i < n && j < m) {
		if(a[i] > b[j]) {
			c[k++] = b[j++];
		} else {
			c[k++] = a[i++];
		}
	}
	while( i < n) {
		c[k++] = a[i++];
	}
	while( j < m) {
		c[k++] = b[j++];
	}
}

void mergesort(int * a,int n) 
{
	int mid, *c,i;
	if( n < 2) {
		return;
	}
	mid  = n / 2;
	c = (int *)malloc( n * sizeof(int));
	mergesort(a,mid);
	mergesort(a + mid,n - mid);
	merge(a,a + mid,c,mid,n - mid);
	for( i = 0; i < n; i++) {
		a[i] = c[i];
	}
	free(c);
}

int main()
{
	int i,n,a[101],sum,son[10],t,k,r;
	cin >> t;
	while(t--) {
		sum = 0;
		son[0] = son[1] = son[2] = son[3] = 0;
		cin >> n >> k;
		for(i = 0; i < n; i++) {
			cin >> a[i];
			sum = sum + a[i];
		}
		mergesort(a,n);
		for(i = 0; i < k; i++) {
			son[0] = son[0] + a[i];
			son[1] = son[1] + a[n - 1 -i];
		}
		son[0] = sum - son[0];
		son[1] = sum - son[1];
		for(i = 0; i < n - k; i++) {
			son[2] = son[2] + a[i];
			son[3] = son[3] + a[n - 1 -i];
		}
		son[2] = sum - son[2];
		son[3] = sum - son[3];
		mergesort(son,4);
		cout << son[3] - son[0] << "\n";
	}
}
