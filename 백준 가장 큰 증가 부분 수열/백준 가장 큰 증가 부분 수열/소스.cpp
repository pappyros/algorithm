#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	
	int n;
	cin >> n;
	vector<int> vi(n), dp(n);
	for (int i = 1; i < n; i++) {
		cin >> vi[i];
	}

	dp[0] = vi[0];
	for (int i = 1; i < n; i++) {
		for (int j = 0; j < i; j++) {
			if (vi[j] < vi[i]) {
				dp[i] = max(dp[i], dp[j] + vi[i]);
			}
		}
	}
	
	sort(dp.begin(),dp.end());
	cout << dp[n - 1];
	
}