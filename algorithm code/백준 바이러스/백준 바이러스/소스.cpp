#include<iostream>
#include<vector>
#include<list>
using namespace std;
typedef class comp *nptr;
int result = 0;
class comp {
public:
	int visit=0;
	int size;
	nptr * child = new nptr[100];
	void add(nptr a) {
		child[size] = a;
		size++;
	}
	
	comp() { visit = 0; 
	size = 0;
	}
	void find(nptr com) {
		com->visit=1;

		for (int i = 0; i < com->size; i++) {
			if (com->child[i]->visit ==0 ) {
				
				com->find(com->child[i]);
				result++;
			}

		}



	}
	
	

};
int main() {
	int comnum, net;
	cin >> comnum >> net;
	comp *Com = new comp[comnum + 1];
	for (int i = 0; i < net; i++) {
		int a, b;
		cin >> a >> b;
		Com[a].add(Com + b);
		Com[b].add(Com + a);
		
		
	}
	 
	Com[0].find(Com + 1);
	cout << result;


}