#include<iostream>

using namespace std;
int func(int a) {
	for (int i = 1; 1; i++) {
		int temp = (i*(i + 1)) / 2;
		if (a == temp) {
			int sum = 0;
			for (int k = 1; k <= i; k++) {
				sum += k*k;
			}
			return sum;
		}
		else if (a<temp) {
			int gap = a - ((i*(i - 1)) / 2);
			int sum = 0;
			for (int k = 1; k < i; k++) {
				sum += k*k;
			}
			sum += i*gap;
			return sum;

		}
	}
}

int main() {
	int a, b;
	cin >> a >> b;
	a = a - 1;
	cout << func(b) - func(a);
	
}