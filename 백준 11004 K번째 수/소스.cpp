#include<vector>
#include<iostream>
#include<algorithm>

using namespace std;
int main() {
	ios_base::sync_with_stdio(false);
	vector<int>arr; int n, k; cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int t; cin >> t; arr.push_back(t);
	}sort(arr.begin(), arr.end());
	cout << arr[k - 1];

}
