#include<iostream>
#include<vector>
#include<deque>
#include<string>
using namespace std;
typedef class comp *nptr;

class comp {
public:
	int visit = 0;
	int name = 0;;
	
	vector<nptr> child;


	comp() {
		visit = 0;

	}

	void dfs(nptr n) {
		for (int i = 0; i < n->child.size(); i++) {
			n->child[i]->name += 1;
			dfs(n->child[i]);
		}
	}

	



};


int main() {

	int a, b;
	cin >> a >> b;
	int **ch = new int*[a];
	for (int i = 0; i < a; i++) {
		ch[i] = new int[b];
		for (int k = 0; k < b; k++) {
			cin >> ch[i][k];
		}
	}
	


	comp **grr = new comp*[a];
	for (int i = 0; i < a; i++) {
		grr[i] = new comp[b];
		
	}


	for (int i = 0; i < a; i++) {
		for (int k = 0; k < b; k++) {
			
				if (i - 1 >= 0) {
					if (ch[i - 1][k] <ch[i][k]) {
						grr[i][k].child.push_back(grr[i - 1] + k);

					}
				}
				if (k - 1 >= 0) {
					if (ch[i][k - 1] <ch[i][k]) {
						grr[i][k].child.push_back(grr[i] + (k - 1));

					}
				}
				if (i + 1 < a) {
					if (ch[i + 1][k] <ch[i][k]) {
						grr[i][k].child.push_back(grr[i + 1] + k);

					}
				}
				if (k + 1 < b) {
					if (ch[i][k + 1] <ch[i][k]) {
						grr[i][k].child.push_back(grr[i] + (k + 1));

					}
				}

			
		}
	}

	grr[0][0].name = 1;
	grr[0][0].dfs(grr[0]);

	cout << grr[a - 1][b - 1].name;


	

}
