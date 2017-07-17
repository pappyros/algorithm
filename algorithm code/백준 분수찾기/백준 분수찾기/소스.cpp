#include<iostream>
using namespace std;
int main() {
	int n;
	cin >> n;
	int k = 0;
	while (true) {
		k++;
		if (n <= (k*(k + 1)) / 2) {
			break;
		}
	}
	n = n - (k*(k - 1) / 2);
	if (k % 2 == 0) {
		cout << n << "/" << k + 1 - n;
	}
	else {
		cout << k + 1 - n << "/" << n;
	}
}