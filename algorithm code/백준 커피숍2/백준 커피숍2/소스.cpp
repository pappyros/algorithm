/*#include<iostream>
#pragma warning(disable:4996)
using namespace std;



class node {
public:
	int start, end, gab, left, right;

};
int number = 0;
int func(node* vrr, int *arr, int  s, int e) {
	

	if (s >= e) {
		int ga = arr[s - 1];
		vrr[number].gab = ga;
		vrr[number].start = s;
		vrr[number].end = e;
		
		return number;

	}
	else {

		int le = func(vrr, arr, s, (s + e) / 2);
		number++;
		int ri = func(vrr, arr, 1 + ((s + e) / 2), e);
		number++;
		int ga = vrr[le].gab + vrr[ri].gab;

		vrr[number].start = s;
		vrr[number].end = e;
		vrr[number].left = le;
		vrr[number].right = ri;
		vrr[number].gab = ga;

		return number;

	}
}
int intvec =  0;
void find(node*vrr, node n, int s, int e) {
	if (n.start >= s&& n.end <= e) {
		intvec += n.gab;
	}
	else if (n.start > e || n.end < s) {

	}
	else {
		find(vrr, vrr[n.left], s, e);
		find(vrr, vrr[n.right], s, e);
	}

}
int find2(node*vrr, node n, int s, int change) {
	int mid = (n.start + n.end) / 2;
	if (n.start == n.end) {
		int cha = change - vrr[n.start].gab;
		vrr[n.start].gab = change;
		return cha;
	}
	if (s <= mid) {
		n.gab += find2(vrr, vrr[n.left], s, change);
		
	}
	else {
		n.gab += find2(vrr, vrr[n.right], s, change);
	}
	
}
int main() {
	int n, m;
	scanf("%d", &n);
	scanf("%d", &m);
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		//cin >> arr[i];
		scanf("%d", &arr[i]);
	}
	node *vrr = new node[(2 * n)];
	func(vrr, arr, 1, n);

	int* result = new int[m];
	for (int i = 0; i < m; i++) {
		int q, w,ind,ga;
		//cin >> q >> w>>ind>>ga;
		scanf("%d", &q);
		scanf("%d", &w);
		scanf("%d", &ind);
		scanf("%d", &ga);
		find(vrr, vrr[(2 * n) - 2], q, w);
		find2(vrr, vrr[(2 * n) - 2], ind, ga);
		
		result[i] = intvec;
		intvec =  0;

	}

	for (int i = 0; i < m; i++) {
		printf("%d\n", result[i]);
	}


}*/

#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
#define MAX 100000000
using namespace std;


long  init(vector<long> &arr, vector<long> &tree, long node, long start, long end)
{
	if (start == end)
		return tree[node] = arr[start];
	else
		return tree[node] = init(arr, tree, node * 2, start, (start + end) / 2)+
			init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end);
}
long sum(vector<long> &tree, long node, long start, long end, long left, long right)
{
	if (left > end || right < start)
		return 0;
	if (left <= start && end <= right)
		return tree[node];

	return sum(tree, node * 2, start, (start + end) / 2, left, right)+
		sum(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right);
}

long update(vector<long> &arr, vector<long> &tree, long node, long start, long end,long index, long change)
{
	long mid = (start + end) / 2;
	if (start == end) {
		long cha = change - tree[node];
		tree[node] = change;
		return cha;
	}
	else if (index <= mid) {
		long imsi= update(arr, tree, node * 2, start, (start + end) / 2, index, change);
		tree[node]+=imsi;
		return imsi;

	}
	else {
		long imsi=update(arr, tree, node*2+1, (start+end)/2+1, end, index, change);
		tree[node]+=imsi;
		return imsi;
	}
}
int main()
{
	long n, m, a, b,c,d;
	scanf("%d %d", &n, &m);
	vector<long> arr(100005), tree(300000);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	init(arr, tree, 1, 0, n - 1);
	long *result = new long [m];
	for (int i = 0; i < m; i++)
	{
		scanf("%d %d %d %d", &a, &b, &c, &d);
		if (a > b) {
			result[i] = sum(tree, 1, 0, n - 1, b - 1, a - 1);

		}
		else {
			result[i] = sum(tree, 1, 0, n - 1, a - 1, b - 1);
		}
		update(arr, tree, 1, 0, n - 1, c-1, d);
	}
	for (int i = 0; i < m; i++) {
		printf("%d\n", result[i]);
	}
	return 0;
}