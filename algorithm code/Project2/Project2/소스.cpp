#include<iostream>
using namespace std;

typedef class node *nptr;

class node {
public:
	int element;
	nptr *child;
	int childnum;

	void create(int value, int n, nptr* a) {
		child = a;
		childnum = n;
		element = value;

	};
	void order(nptr a) {
		for (int i = 0; i < a->childnum; i++) {
			if (a->child[i]) {
				order(a->child[i]);
			}
		}
		cout << a->element << endl;

	}
};
int main() {
	
	node a, b, c;
	nptr r = &a;
	nptr p = &b;
	nptr q = &c;
	b.element = 2;
	c.element = 3;
	nptr* k = new nptr[10];
	k[0] = p;
	k[1] = q;
	a.create(1, 2, k);
	a.order(r);




}