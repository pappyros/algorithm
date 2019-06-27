#include<iostream>
#include<deque>
#include<algorithm>
#include<string>
using namespace std;
int ty[4] = { 1,0,0,-1 }; int tx[4] = { 0,1,-1,0 };
int arr[1001][1001];
bool vrr[1001][1001];
int n, m;
class state {
public:
	int y, x;
};
int main() {
	bool dap = false;
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		string temp; cin >> temp; int sz = temp.size();
		for (int k = 0; k < sz; k++) arr[i][k + 1] = (temp[k] == '1' ? 1 : 0);
	}
	deque<state> qu;
	for (int i = 1; i <= m; i++) {
		if (arr[1][i] == 0) {
			vrr[1][i] = true;
			state ts; ts.y = 1; ts.x = i; qu.push_back(ts);
		}
	}

	while (!qu.empty()) {
		state tp = qu.front();
		if (tp.y == n) {
			dap = true;
			break;
		}
		for (int i = 0; i < 4; i++) {
			if (arr[tp.y + ty[i]][tp.x + tx[i]] == 0 && vrr[tp.y + ty[i]][tp.x + tx[i]] == false && tp.y + ty[i] >= 1 && tp.y + ty[i] <= n&&tp.x + tx[i] >= 1 && tp.x + tx[i] <= m) {
				vrr[tp.y + ty[i]][tp.x + tx[i]] = true;
				state aaa; aaa.y = tp.y + ty[i]; aaa.x = tp.x + tx[i];
				qu.push_back(aaa);
			}
		}qu.pop_front();
	}
	cout << (dap==true?"YES":"NO");
}
