#include<iostream>
#include<vector>
using namespace std;

typedef class node *nptr;
class node {
public:
	int name;
	int visit = 0;
	vector<nptr> child;
	void search(int me,nptr A,int **arr) {
		A->visit = 1;
		arr[me][A->name] = 1;
		for (int i = 0; i < A->child.size(); i++) {
			if (A->child[i]->visit != 1) {
				search(me,A->child[i],arr);
			}
		}

	}
	void start(int me,int **arr) {
		for (int i = 0; i < child.size(); i++) {
			search(me,child[i],arr);
		}

	}
	


};
int main() {

	int N;
	cin >> N;
	node *Node = new node[N];
	int **arr = new int*[N];
	for (int i = 0; i < N; i++) {
		Node[i].name = i;
		arr[i] = new int[N];
		for (int k = 0; k < N; k++) {
			arr[i][k] = 0;
			int aaa;
			cin >> aaa;
			if (aaa == 1) {
				Node[i].child.push_back(Node + k);
			}
		}
	}
	for (int i = 0; i < N; i++) {
		Node[i].start(i, arr);
		for (int k = 0; k < N; k++) {
			Node[k].visit = 0;
		}

	}
	for (int i = 0; i < N; i++) {
		for (int k = 0; k < N; k++) {
			cout << arr[i][k] << " ";
		}
		cout << endl;
	}


}