#include<iostream>
using namespace std;
int main() {
	char **arr = new char*[8];
	for (int i = 0; i < 8; i++) {
		arr[i] = new char[8];
		cin >> arr[i];
	}
	int sum = 0;
	for (int i = 0; i < 8; i++) {
		if (i % 2 == 0) {
			for (int k = 0; k < 8; k = k + 2) {
				if (arr[i][k]=='F') {
					sum++;
				}

			}
		}
		else {
			for (int k = 1; k < 8; k = k + 2) {
				if (arr[i][k] == 'F') {
					sum++;
				}

			}

		}
	}
	cout << sum;

	
}