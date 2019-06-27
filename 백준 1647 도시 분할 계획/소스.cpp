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
node nrr[100001]; bool vrr[100001]; node trr[100001]; int sss = 0; long long int mn = 0; int n,m; int parent[100001]; int level[100001];
priority_queue<edge, vector<edge>, greater<edge>>heap;

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
	cin >> n >> m;
	for (int i = 1; i <= m; i++) {
		int a, b, c; cin >> a >> b >> c;
		edge ed; ed.from = a; ed.to = b; ed.ga = c;
		heap.push(ed);
	}
	
	for (int i = 1; i <= n; i++)
	{
		parent[i] = i;
		level[i] = 1;
	}int mx = 0;
	while (!heap.empty() && sss<n) {
		int f, t; f = heap.top().from; t = heap.top().to;
		if (merge(f, t)) {
			mn += heap.top().ga;
			if (mx < heap.top().ga)mx = heap.top().ga;
			sss++;
		}heap.pop();
	}
	cout << mn-mx;
}
