#include<iostream>
#include<algorithm>
using namespace std;
int arr[40001], dp[40001];
int main() {
	ios_base::sync_with_stdio(false);
	int n, len; cin >> n; len = 1;
	for (int i = n-1; i >=0; i--)cin >> arr[i];

	for (int i = 0; i < n; i++) {
		auto pos = lower_bound(dp, dp + len, arr[i]);
		*pos = arr[i];
		if (pos == (dp + len))len++;
	}
	cout << len - 1;
}
