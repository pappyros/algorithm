#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;

class node {
public:
	vector<int>child;

};

int main() {
	int tc;
	cin >> tc;
	int*arr = new int[tc];
	for (int i = 0; i < tc; i++) {
		try {
			arr[i] = 1;

			int nod, edg;
			cin >> nod >> edg;
			node *nodrr = new node[nod + 1];

			int *nrr = new int[nod + 1];
			for (int k = 0; k <= nod; k++) {
				nrr[k] = k;
			}
			for (int k = 0; k < edg; k++) {
				int from, to;
				cin >> from >> to;
				nodrr[from].child.push_back(to);
				nodrr[to].child.push_back(from);
				if (nodrr[from].child.size() > 3 || nodrr[to].child.size() > 3)throw 0;
				if (nrr[from] == nrr[to]) { throw 0; }
				else {
					nrr[from] = min(nrr[from], nrr[to]);
					nrr[to] = nrr[from];
				}


			}
		
		
		}
		catch (int re) {
			arr[i] = re;
		}



	}

	for (int i = 0; i < tc; i++) {

	
		if (arr[i] == 1) {
			cout << "YES" << endl;

		}
		else {
			cout << "NO" << endl;
		}
	}





}