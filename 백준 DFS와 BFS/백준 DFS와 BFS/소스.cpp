#include<iostream>
#include<vector>
#include<list>
#include<algorithm>
#include<deque>
using namespace std;
typedef class comp *nptr;
vector<int> dfs;
vector<int> BFS;
deque<nptr> bfs;


class comp {
public:
	int visit = 0;
	int name;
	vector<nptr> child;
	

	comp() {
		visit = 0;
		
	}
	void find(nptr com) {
		com->visit = 1;
		dfs.push_back(com->name);

		for (int i = 0; i < com->child.size(); i++) {
			if (com->child[i]->visit == 0) {

				com->find(com->child[i]);
				
			}

		}

	}
	void Bread(nptr a) {
		BFS.push_back(a->name);
		
		for (int i = 0; i < a->child.size(); i++) {
			if (a->child[i]->visit != 1) {
				a->child[i]->visit = 1;
				bfs.push_back(a->child[i]);
			}
		}
	}
};

class point {
public:
	int x, y;
};
bool func(point a, point b) {
	if (a.x == b.x) {
		return a.y < b.y;
	}
	else {
		return a.x < b.x;
	}
}
int main() {
	int G, E, S;
	cin >> G >> E >> S;
	vector<int> arr;
	comp *grr = new comp[G];
	point *prr = new point[2 * E];

	for (int i = 0; i < 2*E; i=i+2) {
		int a, b;
		cin >> a >> b;
		prr[i].x = a;
		prr[i].y = b;
		prr[i+1].y = a;
		prr[i+1].x = b;
		
		
		
		
	}
	sort(prr,prr+(2*E),func);
	


	for (int i = 0; i < 2*E; i++) {
		int a, b;
		a = prr[i].x;
		b = prr[i].y;
		grr[a - 1].child.push_back(grr + b - 1);

	}


	for (int i = 0; i < G; i++) {
		grr[i].name = i + 1;

	}


	//DFS
	grr[S].find(grr + S-1);
	for (int i = 0; i < G; i++) {
		
		if (grr[i].visit != 1) {
			grr[i].find(grr + i);
		}

	}
	for (int i = 0; i < G; i++) {
		grr[i].visit = 0;

	}
	//BFS
	
	bfs.push_back(grr + S - 1);
	grr[S - 1].visit = 1;
	while (bfs.empty() != true) {
		grr[S].Bread(bfs[0]);
		bfs.pop_front();

	}
	
	
	//Ãâ·Â
	for (int i = 0; i < dfs.size(); i++) {
		cout << dfs[i]<<" ";
	}
	cout << endl;
	
	for (int i = 0; i < BFS.size(); i++) {
		cout << BFS[i] << " ";
	}
	

}

	