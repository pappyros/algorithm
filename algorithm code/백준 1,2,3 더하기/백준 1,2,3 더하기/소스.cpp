#include<iostream>
using namespace std;

int com(int n) {
	if (n == 0) {
		return 1;
	}
	if (n == 1) {
		return 1;

	}
	else if (n == 2) {
		return 2;
	}
	else if (n == 3) {
		return 4;
	}
	return com(n - 1) + com(n - 2) + com(n - 3);
	
}

int main() {
	int tc;
	cin >> tc;
	int * arr = new int[tc];
	for (int i = 0; i < tc; i++) {
		int aaa;
		cin >> aaa;
	
		arr[i] = com(aaa);


	}
	for (int i = 0; i < tc; i++) {
		cout << arr[i] << endl;
	}
}