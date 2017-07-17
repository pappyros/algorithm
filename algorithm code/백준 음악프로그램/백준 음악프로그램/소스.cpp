#include<iostream>
#include<vector>
using namespace std;
vector<int>result;
class node {
public:
	vector<int>child;
	
	
};
void find(node*nrr, int *visit, int p,int*dv) {
	if (dv[p] == 1) {
		result.push_back(0);
		return;
	}
	dv[p] = 1;
	
	for (int i = 0; i < nrr[p].child.size(); i++) {
		if (visit[nrr[p].child[i]] == 0) {
			
		
			find(nrr, visit, nrr[p].child[i],dv);
		}
		

	}
	result.push_back(p);
	dv[p] = 0;
	
	visit[p] = 1;


}

int main() {
	int n, pd;
	cin >> n >> pd;
	
	node *ndr = new node[1000];
	for (int i = 0; i < pd; i++) {
		int k;
		cin >> k;
		vector<int>imsi;
		for (int p = 0; p < k; p++) {
			int gap;
			cin >> gap;
			imsi.push_back(gap);
		}
		if (imsi.size() == 1&& imsi.size() == 0) {
			continue;
		}
		else {
			for (int v = 0; v < imsi.size() - 1; v++) {
				ndr[imsi[v + 1]-1].child.push_back(imsi[v]-1);
			}
		}

	}
	int *visit = new int[1000];
	int *doublevisit = new int[1000];
	for (int i = 0; i < n; i++) {
		doublevisit[i] = 0;
		visit[i] = 0;
	}
	for (int i = 0; i < n; i++) {
		if (visit[i] == 1) { continue; }
		find(ndr, visit, i,doublevisit);

	}

	
	if (result.size() > n) {
		cout << 0;
	}
	else {
		for (int i = 0; i < result.size(); i++) {
			cout << result[i] + 1 << endl;
		}
	}

}