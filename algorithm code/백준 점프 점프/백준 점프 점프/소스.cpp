#include<iostream>
#include<vector>
using namespace std;

int main() {

	int n;
	cin >> n;

	int *arr = new int[n+1];
	for (int i = 1; i <= n; i++) {
		cin >> arr[i];
	}
	int *dp = new int[n+1];
	dp[1] = 0;

	for (int i = 2; i <= n; i++) {
		int imsi = 99999;
		if (i <= 103) {
			for (int k = 1; k < i; k++) {
				if (arr[k] + k >= i&&(dp[k]<imsi)) {
					imsi = dp[k];
				}
			}
			dp[i] = imsi+1;

		}
		else {
			for (int k = i - 101; k < i; k++) {
				if (arr[k] + k >= i && (dp[k]<imsi)) {
					imsi = dp[k];
				}

			}
			dp[i] = imsi+1;

		}
		
		


	}
	if (dp[n] >= 90000) {
		cout << -1;
	}
	else {
		cout << dp[n];
	}
	
}