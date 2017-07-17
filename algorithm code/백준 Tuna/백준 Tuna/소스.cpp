#include<iostream>
#include<cmath>

using namespace std;

int main() {
	int tuna;
	cin >> tuna;
	int X;
	cin >> X;
	int sum = 0;
	for (int i = 0; i < tuna; i++) {
		int a, b;
		cin >> a >> b;
		int cha = abs(a - b);
		if (cha <= X) {
			if (a > b) {
				sum += a;
			}
			else {
				sum += b;
			}
		}
		else {
			int the;
			cin >> the;
			sum += the;
		}

	}

	cout << sum;
}