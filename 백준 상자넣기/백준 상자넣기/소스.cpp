#include<iostream>

using namespace std;
int main() {
	int n;
	cin >> n;
	int *arr = new int[n];
	int *dp = new int[n];
	
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	dp[0] = 1;
	for (int i = 1; i < n; i++) {
		int max = 0;
		for (int k = i+1; k < n; k++) {
			if (arr[k] > arr[i]) {
				dp[k] = dp[k - 1] + 1;

			}

		}
	}
	
	cout << dp[n - 1];
}