#include<iostream>
#include<algorithm>
#pragma warning(disable:4996);
using namespace std;

int main() {
	int n, m;
	scanf("%d%d", &n, &m);

	int **arr = new int*[n];
	int **dp = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[m];
		dp[i] = new int[m];
		for (int k = 0; k < m; k++) {
			scanf("%d",&arr[i][k]);
		}
	}
	dp[0][0] = arr[0][0];
	for (int i = 1; i < m; i++) {
		dp[0][i] = dp[0][i - 1] + arr[0][i];

	}
	for (int i = 1; i < n; i++) {
		dp[i][0] = arr[i][0] + dp[i - 1][0];
	}
	for (int i = 1; i < n; i++) {
		for (int k = 1; k < m; k++) {
			dp[i][k] = arr[i][k] + max(dp[i - 1][k], dp[i][k - 1]);
		}
	}
	printf("%d",dp[n - 1][m - 1]);
}