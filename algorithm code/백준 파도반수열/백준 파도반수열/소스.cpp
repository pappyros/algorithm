#include<iostream>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	long long int *arr = new long long int[tc];
	for (int i = 0; i < tc; i++) {
		int A;
		cin >> A;
		long long int *line = new long long int[101];
		line[0] = 1;
		line[1] = 1;
		line[2] = 1;
		for (int i = 3; i <= A; i++) {
			line[i] = line[i - 3] + line[i - 2];
		}
		if (A <= 3) {
			arr[i] = 1;
		}
		else {
			arr[i] = line[A-1];


		}

	}

	for (int i = 0; i < tc; i++) {
		cout << arr[i] << endl;
	}
}