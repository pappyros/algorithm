#include<iostream>
#include<vector>
using namespace std;
int got = -1;
class node {
public:
	int visit=0;
	vector<int> child;
};
void fffff(node *nrr,int depth,int index, int who) {
	nrr[index].visit = 1;
	if (index == who) {
		
		got= depth;
	}
	else {
		for (int i = 0; i < nrr[index].child.size(); i++) {
			if (nrr[nrr[index].child[i]].visit == 0) {
				fffff(nrr, depth + 1, nrr[index].child[i], who);
			}

		}
	}
	nrr[index].visit = 0;

}
int main() {

	int num;
	cin >> num;
	int from, to, rel;
	node*nrr = new node[num + 1];
	cin >> from >> to>>rel;
	for (int i = 0; i < rel; i++) {
		int pa, ch;
		cin >> pa >> ch;
		nrr[pa].child.push_back(ch);
		nrr[ch].child.push_back(pa);
	}
	fffff(nrr, 0, from, to);
	cout << got;

}