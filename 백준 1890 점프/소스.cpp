#include<iostream>
#include<vector>
using namespace std; int arr[101][101]; unsigned long long int dp[101][101]; int n;
unsigned long long int dfs(int y, int x) {
	if (y == n&&x == n)return 1;
	if (arr[y][x] == 0)return 0;
	if (y != 0 && x != 0 && dp[y][x] != 0) return dp[y][x];
	if (y + arr[y][x] <= n) dp[y][x] += dfs(y + arr[y][x], x);
	if (x + arr[y][x] <= n) dp[y][x] += dfs(y , x + arr[y][x]);
	return dp[y][x];
}
int main() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		fill(dp[i], dp[i] + 1 + n, 0);
		for (int k = 1; k <= n; k++)cin >> arr[i][k];
	}dfs(1, 1);cout << dp[1][1];
}
