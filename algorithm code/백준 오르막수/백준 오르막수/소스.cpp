#include<iostream>
using namespace std;


int main() {

	int n;
	cin >> n;
	long long int **arr = new long long int*[10];
	for (int i = 0; i < 10; i++) {
		arr[i] = new long long int[2];
	}
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			for (int k = 0; k < 10; k++) {
				arr[k][0] = k + 1;
			}
		}
		else {
			for (int k = 0; k < 10; k++) {
				if (k == 0) {
					arr[0][1] = 1;
					continue;
				}
				arr[k][1] = (arr[k - 1][1]%10007 + arr[k][0]%10007)%10007;
			}
			for (int k = 0; k < 10; k++) {
				arr[k][0] = arr[k][1];
			}

		}
	}

	cout << arr[9][0];

}