#include<iostream>
#include<vector>
using namespace std;

class node {
public:
	bool leaf = true;
	int parent;
	vector<int>child;
};

void func(node *nrr, int del) {
	nrr[del].leaf = false;
	for (int i = 0; i < nrr[del].child.size(); i++) {
		func(nrr, nrr[del].child[i]);
	}
}
int main() {

	int n;
	cin >> n;
	node *nrr = new node[n];
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		if (a == -1) {
			continue;
		}
		nrr[a].child.push_back(i);
		nrr[a].leaf = false;
		nrr[i].parent = a;
	}

	int del;
	cin >> del;
	if (nrr[nrr[del].parent].child.size() == 1) {
		nrr[nrr[del].parent].leaf = true;
	}
	func(nrr, del);

	int soo = 0;
	for (int i = 0; i < n; i++) {
		if (nrr[i].leaf == true) {
			soo++;
		}
	}
	cout << soo;

}

