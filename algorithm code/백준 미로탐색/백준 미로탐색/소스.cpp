#include<iostream>
#include<vector>
#include<deque>
#include<string>
using namespace std;
typedef class comp *nptr;
vector<int> BFS;
deque<nptr> bfs;
int one = 2;
class comp {
public:
	int visit = 0;
	int name;
	int x, y;
	int bun = 0;
	vector<nptr> child;


	comp() {
		visit = 0;

	}
	
	void Bread(nptr a) {
		BFS.push_back(a->name);

		for (int i = 0; i < a->child.size(); i++) {
			if (a->child[i]->visit != 1) {
				a->child[i]->bun = a->bun+1 ;
				a->child[i]->visit = 1;
				bfs.push_back(a->child[i]);
			}
		}
		one++;
	}



};


int main() {

	int a, b;
	cin >> a >> b;
	string **ch= new string*[a];
	for (int i = 0; i < a; i++) {
		string a;
		cin >> a;
		ch[i] = new string[b];
		for (int k = 0; k < b; k++) {
			ch[i][k] = a.substr(k, 1);
		}
	}
	
	
	comp **grr = new comp*[a];
	for (int i = 0; i < a; i++) {
		grr[i] = new comp[b];
		for (int k = 0; k < b; k++) {
			grr[i][k].x = k;
			grr[i][k].y = i;
		}
	}
	
	
	for (int i = 0; i < a; i++) {
		for (int k = 0; k < b; k++) {
			if (ch[i][k]=="1") {
				if (i - 1 >= 0) {
					if (ch[i - 1][k] == "1") {
						grr[i][k].child.push_back(grr[i - 1] + k);
					
					}
				}
				if (k - 1 >= 0) {
					if (ch[i][k - 1] == "1") {
						grr[i][k].child.push_back(grr[i] + (k - 1));
						
					}
				}
				if (i + 1 < a) {
					if (ch[i + 1][k] == "1") {
						grr[i][k].child.push_back(grr[i + 1] + k);
						
					}
				}
				if (k + 1 < b) {
					if (ch[i][k + 1] == "1") {
						grr[i][k].child.push_back(grr[i] + (k + 1));
					
					}
				}

			}
		}
	}

	
	///BFS
	grr[0][0].bun = 1;
	bfs.push_back(grr[0]);
	grr[0][0].visit = 1;
	while (bfs.empty() !=true) {
		
		grr[0][0].Bread(bfs[0]);
		if (bfs[0]->x == (b - 1) && bfs[0]->y == (a - 1)) {
			cout << bfs[0]->bun;
			break;
		}
		else {

		}
		bfs.pop_front();
		

	}

}
