#include <stdio.h>
#include <queue>
#include <vector>
using namespace std;
#define MN 1005
struct Graph {
	int v;
	long long w;
	bool operator < (const Graph v1) const { return v1.w < w; }
} V, R;
int n, m, S, E;
long long d[MN];
vector <Graph> g[MN];
int main() {
	scanf("%d%d", &n, &m);
	int v1, v2;
	long long cost;
	for (int i = 1; i <= m; i++) {
		scanf("%d%d%lld", &v1, &v2, &cost);
		V.v = v2; V.w = cost; g[v1].push_back(V);
	}
	scanf("%d%d", &S, &E);
	priority_queue <Graph> Q;
	for (int i = 1; i <= n; i++) d[i] = -1;
	d[S] = 0;
	for (int i = 0; i < g[S].size(); i++) {
		Q.push(g[S][i]);
		if (d[g[S][i].v] == -1 || d[g[S][i].v] > g[S][i].w) d[g[S][i].v] = g[S][i].w;
	}
	while (!Q.empty()) {
		V = Q.top(); Q.pop();
		if (V.w > d[V.v]) continue;
		for (int i = 0; i < g[V.v].size(); i++) {
			if (d[g[V.v][i].v] == -1 || d[g[V.v][i].v] > V.w + g[V.v][i].w) {
				d[g[V.v][i].v] = V.w + g[V.v][i].w;
				R.v = g[V.v][i].v; R.w = d[R.v];
				Q.push(R);
			}
		}
	}
	printf("%lld", d[E]);
	return 0;
}