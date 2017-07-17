#include<iostream>
using namespace std;
int main() {
	int tc;
	
	cin >> tc;
	int *arr = new int[tc];
	for (int i = 0; i < tc; i++) {
		long double a, b, c;
		c = 1;
		cin >> a >> b;
		for (int i = 1; i<=a; i++) {
			c = c*b / i;
			b--;
			
			
		}
		arr[i] = c;


	}
	for (int i = 0; i < tc; i++) {
		cout << arr[i] << endl;
	}
}