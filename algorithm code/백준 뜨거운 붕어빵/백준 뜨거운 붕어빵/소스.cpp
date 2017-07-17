#include<iostream>
using namespace std;

int main() {
	int A, B;
	cin >> A >> B;
	char **arr = new char*[A];
	for (int i = 0; i < A; i++) {
		arr[i] = new char[B];
		cin >> arr[i];

	}


	for (int i = 0; i < A; i++) {
		for (int k = B - 1; k >= 0; k--) {
			cout << arr[i][k];
		}
		cout << endl;
	}
	
}