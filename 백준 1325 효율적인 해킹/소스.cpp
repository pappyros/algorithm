#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
bool vrr[10001]; int sum = 0; int mx = 0; int qrr[10001];
class node {
public:
	vector<int>child;
}; node nrr[10001];
void dfs(int k) {
	sum++;
	vrr[k] = true;
	for (int i = 0; i < nrr[k].child.size(); i++) {
		if (vrr[nrr[k].child[i]] == false) {
			dfs(nrr[k].child[i]);
		}
	}
}
int main() {
	int n, m; cin >> n >> m; vector<int>res;
	for (int i = 1; i <= m; i++) {
		int a, b; cin >> a >> b;
		nrr[b].child.push_back(a);
	}
	for (int i = 1; i <= n; i++) {
		dfs(i);
		qrr[i] = sum; if (mx < sum)mx = sum;
		sum = 0; fill(vrr, vrr + 10001, false);
	}
	for (int i = 1; i <= n; i++) {
		if (qrr[i] == mx)res.push_back(i);
	}
	for (int i = 0; i < res.size(); i++)cout << res[i] << " ";
}
