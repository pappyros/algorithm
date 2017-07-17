#include<iostream>

using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	int sum = 0;
	int min = 0;
	for (int i = a; i <= b; i++) {
		for (int k = 2; k <= i; k++) {
			if (k == i) {
				if (min == 0) {
					min = i;
				}
				sum += i;
			}
			if (i%k == 0) {
				break;
			}

		}

	}
	if (min == 0) {
		cout << -1;
	}
	else {
		cout << sum << endl;
		cout << min << endl;
	}
	
}