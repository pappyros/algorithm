#include<iostream>
#include<cmath>
using namespace std;
int main() {
	int n; cin >> n; int k;
	for (int i = 2; i <= 100; i++) {
		int tp = (pow(i, 3) - 1) / (i - 1);
		if (tp == n)k = i;
	}
	cout << (n == 3 ? 1 : k);
}
