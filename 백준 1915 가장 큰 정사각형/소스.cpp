#include<iostream>
#include<string>
#include<algorithm>
using namespace std; bool arr[1001][1001]; int drr[1001][1001];
int main() {
	int n, m; cin >> n >> m;
	for (int i = 1; i <= n; i++) {
			string str; cin >> str;
			for (int q = 0; q < str.size(); q++) {
				arr[i][q+1] = (str[q] == '1' ? 1 : 0);
			}
	}int dap = 0;
	for (int i = n; i >= 1; i--) {
		for (int k = 1; k <= m; k++) {
			if (i == n || k == 1) drr[i][k] = arr[i][k];
			else {
				drr[i][k] = (arr[i][k] == 0 ? 0 : 1 + min(drr[i][k - 1], min(drr[i + 1][k - 1], drr[i + 1][k])));
			};
			if (drr[i][k] > dap)dap = drr[i][k];
		}
	}
	cout << dap*dap;
}
