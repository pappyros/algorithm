#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
int arr[1001][2];
long int dp[1001][1001];
long int func(int f, int t) {
	if (f == t)return 0;
	if (dp[f][t] != 0)return dp[f][t];
	long int mi =2000000000;
	for (int i = f; i < t; i++) {
	mi = min(mi, func(f, i) +func(i+1,t)+ arr[f][0] * arr[i][1] * arr[t][1]);
	}
	dp[f][t] = mi;
	return dp[f][t];
}
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> arr[i][0] >> arr[i][1];
	cout << func(1, n);
}
