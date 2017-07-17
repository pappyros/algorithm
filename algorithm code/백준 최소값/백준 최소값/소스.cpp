#include<iostream>
using namespace std;

class node {
public:
	int start, end, gab, left, right;

};
int number = 0;
int func(node* vrr,int *arr, int  s, int e) {
	node no;
	no.start = s;
	no.end = e;
	
	if (s >= e) {
		no.gab = arr[s - 1];
		vrr[number] = no;
		
		return number;
	
	}
	else {
		
		no.left = func(vrr,arr, s, (s + e) / 2);
		number++;
		no.right = func(vrr,arr, 1 + ((s + e) / 2), e);
		number++;
		if (vrr[no.left].gab > vrr[no.right].gab) {
			no.gab = vrr[no.right].gab;
		}
		else {
			no.gab = vrr[no.left].gab;
		}
	
		vrr[number] = no;
		
		return number;
		
	}
}
int intvec=1000000001;
void find(node*vrr,node n, int s, int e) {
	if (n.start >= s&& n.end <= e) {
		if (n.gab < intvec) {
			intvec = n.gab;
		}
	}
	else if (n.start > e || n.end < s) {

	}
	else {
		find(vrr,vrr[n.left], s, e);
		find(vrr,vrr[n.right], s, e);
	}

}
int main() {
	int n, m;
	cin >> n >> m;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	node *vrr = new node[(2 * n)];
	func(vrr,arr, 1, n);

	int* result = new int[m];
	for (int i = 0; i < m; i++) {
		int q, w;
		cin >> q >> w;
		find(vrr,vrr[(2 * n) - 2], q, w);
		result[i] = intvec;
		intvec = 1000000001;
		
	}

	for (int i = 0; i < m; i++) {
		cout << result[i] << endl;
	}
	

}