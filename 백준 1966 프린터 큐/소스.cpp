#include<iostream>
#include<queue>
#include<deque>
#include<functional>
#include<vector>
#include<algorithm>
using namespace std;
class cl {
public:
	int num; int us;
};
int main() {
	int tc; cin >> tc; vector<int>res;
	for (int q = 0; q < tc; q++) {
		vector<cl>heap;
		int n, m; cin >> n >> m;
		for (int i = 0; i < n; i++) {
			cl cc; cc.num = i; cin >> cc.us;
			heap.push_back(cc);
		}int dap = 1;
		while (!heap.empty()) {
			bool swit = true;
			for (int i = 1; i < heap.size(); i++) {
				if (heap[0].us < heap[i].us) {
					cl l = heap[0]; heap.erase(heap.begin()); heap.push_back(l); swit = false; break;
				}
			}
			if (swit) {
				if (heap[0].num == m) {
					res.push_back(dap);
				}
				heap.erase(heap.begin());
				dap++;
			}

		}
	}
	for (int i = 0; i < tc; i++) {
		cout << res[i] << endl;
	}
}
