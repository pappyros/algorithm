#include<iostream>

using namespace std;


int main() {

	int n;
	long long int m;
	cin >> n >> m;
	long long int result=0;
	long long int *arr = new long long int[n];

	for (int i = 0; i < n; i++) {

		cin >> arr[i];
	}

	for (int i = 0; i < n; i++) {

		long long int sum = 0;
		for (int k = i; k < n; k++) {
			if (m == sum + arr[k]) {
				result++;
				break;
			}
			if (m > sum + arr[k]) {
				sum = sum + arr[k];
			}
			else {
				break;
			}

		}
	}

	cout << result;

}