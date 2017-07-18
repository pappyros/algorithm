#include<iostream>
#include<vector>
#include<deque>

using namespace std;

class node {
public:
	vector<int>child;
	int visit = 0;
	int num;

};



int main() {

	int num;
	cin >> num;
	int*arr = new int[num+1];
	node*nrr = new node[num + 1];

	for (int i = 0; i <= num; i++) {
		nrr[i].num = i;
		arr[i] = 0;
	}

	int rel;
	cin >> rel;
	for (int i = 0; i < rel; i++) {
		int from, to;
		cin >> from >> to;
		nrr[from].child.push_back(to);
		nrr[to].child.push_back(from);
	}
	vector<int>temp;
	for (int i = 0; i < nrr[1].child.size(); i++) {
		temp.push_back(nrr[1].child[i]);
		nrr[nrr[1].child[i]].visit = 1;
		arr[nrr[1].child[i]] = 1;
	}
	for (int i = 0; i < temp.size(); i++) {
		for (int k = 0; k < nrr[temp[i]].child.size(); k++) {
			if (nrr[nrr[temp[i]].child[k]].visit == 0) {
				arr[nrr[temp[i]].child[k]] = 1;
			}
		}
	}
	

	int cnt = 0;
	for (int i = 2; i<= num; i++) {
		if (arr[i] == 1) {
			cnt++;
		}
	}
	cout << cnt;



}