#include<iostream>
using namespace std;
int n, m; int arr[1001][1001]; int dp[1001][1001]; int fl[1001][1002]; int fr[1001][1002];


int main() {
	cin >> n>>m;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			cin >> arr[i][k];
		}fl[i][1] = arr[i][1]; fr[i][m] = arr[i][m];
		for (int k = 2; k <= m; k++)fl[i][k] = fl[i][k - 1] + arr[i][k];
		for (int k = m - 1; k >= 1; k--)fr[i][k] = fr[i][k + 1] + arr[i][k];
	}
	for (int i = 1; i <= m; i++)dp[1][i] = fl[1][i];
	for (int i = 2; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			int tp = -999999999; int aa;
			for (int p = 1; p <= k; p++) {
				aa = dp[i - 1][p];
				aa += (fl[i][k] - fl[i][p - 1]);
				if (tp < aa)tp = aa;
			}
			for (int p = m; p >= k; p--) {
				aa = dp[i - 1][p];
				aa += (fr[i][k] - fr[i][p + 1]);
				if (tp < aa)tp = aa;
			}
			dp[i][k] = tp;
		}
	}
	
	cout << dp[n][m];
}

