#include<iostream>
#include<vector>
#include<functional>
#include<algorithm>
#include<queue>
#include<cmath>
using namespace std;
class node {
public:
	int num;
	int x, y, z;
};
class edge {
public:
	int from, to, ga;
	bool operator > (const edge& rhs) const { return (ga > rhs.ga); };
};
node nrr[100001]; bool vrr[100001]; node trr[100001]; int sss = 0; long long int mn = 0; int n; int parent[100001]; int level[100001];
priority_queue<edge, vector<edge>, greater<edge>>heap;
bool xs(node a, node b) {
	return a.x > b.x;
}
bool ys(node a, node b) {
	return a.y > b.y;
}
bool zs(node a, node b) {
	return a.z > b.z;
}
int find(int u)
{
	
	if (u == parent[u])
		return u;

	return parent[u] = find(parent[u]);
}
bool merge(int u, int v)
{
	u = find(u);
	v = find(v);
	if (u == v)
		return false;
	if (level[u] > level[v])
		swap(u, v); 
	parent[u] = v;
	if (level[u] == level[v])
		++level[v];
	return true;
}

int main() {
	 cin >> n;
	for (int i = 1; i <= n; i++) {
		int a, b, c; cin >> a >> b >> c;
		nrr[i].x = a; nrr[i].y = b; nrr[i].z = c; nrr[i].num = i; trr[i].x = a; trr[i].y = b; trr[i].z = c; trr[i].num = i;
	}

	sort(trr+1, trr+n+1,xs);
	for (int i = 2; i <= n; i++) {
		edge te1; te1.from = trr[i - 1].num; te1.to = trr[i].num; te1.ga = abs(trr[i].x - trr[i - 1].x);
		edge te2; te2.from = trr[i].num; te2.to = trr[i-1].num; te2.ga = abs(trr[i].x - trr[i - 1].x);
		heap.push(te1); heap.push(te2);
	}
	sort(trr + 1, trr + n + 1, ys);
	for (int i = 2; i <= n; i++) {
		edge te1; te1.from = trr[i - 1].num; te1.to = trr[i].num; te1.ga = abs(trr[i].y - trr[i - 1].y);
		edge te2; te2.from = trr[i].num; te2.to = trr[i - 1].num; te2.ga = abs(trr[i].y - trr[i - 1].y);
		heap.push(te1); heap.push(te2);
	}
	sort(trr + 1, trr + n + 1, zs);
	for (int i = 2; i <= n; i++) {
		edge te1; te1.from = trr[i - 1].num; te1.to = trr[i].num; te1.ga = abs(trr[i].z - trr[i - 1].z);
		edge te2; te2.from = trr[i].num; te2.to = trr[i - 1].num; te2.ga = abs(trr[i].z - trr[i - 1].z);
		heap.push(te1); heap.push(te2);
	}
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		level[i] = 1;
	}
	while (!heap.empty()&&sss<n) {
		int f, t; f = heap.top().from; t = heap.top().to;
		if (merge(f, t)) {
			mn += heap.top().ga;
			sss++;
		}heap.pop();
	}
	cout << mn;
}
