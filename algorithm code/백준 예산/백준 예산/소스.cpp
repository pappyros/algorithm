#include<iostream>
#include<algorithm>

using namespace std;

int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + n);
	int m;
	cin >> m;
	int result;
	for (int i = 0; i < n; i++) {
		if (arr[i] * (n - i) > m) {
			result = m / (n - i);
			break;
		}
		else {
			m = m-arr[i];

		}
		if (i == n-1) {
			result = arr[i];
		}
	}

	cout << result;



}