#include<iostream>
using namespace std;

int func(int a,int n) {
	if (a == 0) {
		return n;
	}
	if (1 <= a &&a< 3) {
		return -1;
	}
	if (a % 5 == 0) {
		return n+a / 5;
	}
	else {
		return func(a - 3, n + 1);
	}

}
int main() {
	int sugar;
	cin >> sugar;

	cout << func(sugar, 0);
}