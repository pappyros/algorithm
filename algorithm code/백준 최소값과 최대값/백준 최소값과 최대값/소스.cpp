#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
#define MAX 1000000000
using namespace std;
int init(vector<int> &arr, vector<int> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	else
		return tree[node] = min(init(arr, tree, node * 2, start, (start + end) / 2),
			init(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end));
}
int minit(vector<int> &arr, vector<int> &tree, int node, int start, int end)
{
	if (start == end)
		return tree[node] = arr[start];
	else
		return tree[node] = max(minit(arr, tree, node * 2, start, (start + end) / 2),
			minit(arr, tree, node * 2 + 1, (start + end) / 2 + 1, end));
}
int MIN(vector<int> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return MAX;
	if (left <= start && end <= right)
		return tree[node];

	return min(MIN(tree, node * 2, start, (start + end) / 2, left, right),
		MIN(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int Max(vector<int> &tree, int node, int start, int end, int left, int right)
{
	if (left > end || right < start)
		return -1;
	if (left <= start && end <= right)
		return tree[node];

	return max(Max(tree, node * 2, start, (start + end) / 2, left, right),
		Max(tree, node * 2 + 1, (start + end) / 2 + 1, end, left, right));
}
int main()
{
	int n, m, a, b;
	scanf("%d %d", &n, &m);
	vector<int> arr(100005), mtree(300000), Mtree(300000);
	for (int i = 0; i < n; i++)
		scanf("%d", &arr[i]);

	init(arr, mtree, 1, 0, n - 1);
	minit(arr, Mtree, 1, 0, n - 1);
	int *mresult = new int[m];
	int *Mresult = new int[m];
	for(int i=0;i<m;i++)
	{
		scanf("%d %d", &a, &b);
		mresult[i]=MIN(mtree, 1, 0, n - 1, a - 1, b - 1);
		Mresult[i]=Max(Mtree, 1, 0, n - 1, a - 1, b - 1);
	}
	for (int i = 0; i<m; i++)
	{
		printf("%d %d\n", mresult[i], Mresult[i]);
	}
	return 0;
}