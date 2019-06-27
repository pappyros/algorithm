#include<iostream>
using namespace std;
int main() {
	int n;int m=0; cin >> n;
	n = 1000 - n;
	m += n / 500; n -= 500 * m;
	int t = n / 100; m += t; n -= t * 100;
	t = n / 50; m += t; n -= t * 50; t = n / 10; m += t; n -= t * 10; t = n / 5; m += t; n -= t * 5; t = n / 1; m += t; n -= t * 1; cout << m;
}
