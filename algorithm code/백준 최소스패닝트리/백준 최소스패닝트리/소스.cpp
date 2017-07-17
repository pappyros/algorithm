#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#pragma warning(disable:4996)


using namespace std;
int visit[10001];
int sum = 0;
class line {
public:
	int from, to, weight;
	bool operator > (const line& rhs) const { return (weight > rhs.weight); };
};
class node {
public:
	

};

void func(node*nrr,int total) {
	int v = 1;
	
	priority_queue<line, vector<line>, greater<line>>heap;
	line li;
	li.weight = 9999999;
	li.to = 1;
	heap.push(li);
	while(total--) {
		visit[v] = 1;
		for (int k = 0; k < nrr[v].child.size(); k++) {
			if (visit[nrr[v].child[k].to] != 1) {
				heap.push(nrr[v].child[k]);//간선들을 힙에 추가
			}
		}
		while (!heap.empty()) {
			if (visit[heap.top().to] == 1) {
				heap.pop();
			}
			else {
				v = heap.top().to;
				sum += heap.top().weight;
				heap.pop();
				
				break;
			}
		}

	}
}

int main() {

	int n, m;
	//cin >> n >> m;
	scanf("%d%d", &n, &m);
	node* nrr = new node[n + 1];
	for (int i = 0; i < m; i++) {
		int f, t, w;
		//cin >> f >> t >> w;
		scanf("%d%d%d", &f, &t, &w);
		line li;
		li.from = f;
		li.to = t;
		li.weight = w;
		line li2;
		li2.from = t;
		li2.to = f;
		li2.weight = w;
		nrr[t].child.push_back(li2);
		nrr[f].child.push_back(li);
	}
	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
	}
	func(nrr, n);
	printf("%d",sum);

}
