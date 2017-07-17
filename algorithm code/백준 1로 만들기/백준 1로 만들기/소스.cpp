#include<iostream>
#include<cmath>
using namespace std;

int func(int num, int g) {
	if (num == 1) {
		return g;
	}
	if (num % 3 == 0 && num % 2 == 0) {
		int A=func(num / 3, g+1);
		int B=func(num / 2, g + 1);
		if (A < B) {
			return A;
		}
		else {
			return B;
		}
	}
	else if (num % 3 == 0) {
		return func(num / 3, g + 1);

	}
	else if (num % 2 == 0) {
		int A = func(num -1, g + 1);
		int B = func(num / 2, g + 1);
		if (A < B) {
			return A;
		}
		else {
			return B;
		}

	}
	else {
		return func(num - 1, g + 1);
	}
}

int main() {

	int Number;
	cin >> Number;
	


	



	cout << func(Number, 0);
}