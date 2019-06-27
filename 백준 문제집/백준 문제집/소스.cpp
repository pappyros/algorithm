#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
using namespace std;
vector<int>result;
class node {
public:
	int visit = 0;
	//priority_queue<int, vector<int>, greater<int>>to;
	//priority_queue<int, vector<int>, greater<int>>from;
	vector<int> to;
	int from=0;
};
void func(int index,node *nrr) {
	nrr[index].visit = 1;
	result.push_back(index);

	for (int i = 0; i < nrr[index].to.size(); i++) {
		nrr[nrr[index].to[i]].from-=1;
	}
	


}
int main() {

	int n, k;
	cin >> n >> k;
	
	node *nrr = new node[n + 1];
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		nrr[a].to.push_back(b);
		nrr[b].from++;
	}
	while (result.size() != n) {
		for (int i = 1; i <= n; i++) {
			if (nrr[i].from== 0 && nrr[i].visit == 0) {
				func(i, nrr);
				break;
			}

		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << " ";
	}

}