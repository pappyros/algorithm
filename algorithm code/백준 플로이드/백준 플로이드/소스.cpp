
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#pragma warning(disable:4996)
#define inf 99999999;
using namespace std;
int dist[101];
int visit[101];

class line {
public:
	int index, value;
	bool operator > (const line& rhs) const { return (value > rhs.value); };//우선순위큐 대소조건

};
class node {

public:

	priority_queue<line, vector<line>, greater<line>>child;//child에 쌓인 값을 나중에 아래의 vchild로 옮겨담을거임
	vector<line>vchild;

};/*
  void dij(node*nrr,int index,int n) {
  int zebal = inf;
  int find;
  for (int i = 1; i < n; i++) {
  if (zebal > dist[i]&&visit[i]==0) {
  zebal = dist[i];
  find = i;
  }
  }
  //일단 들렸음을 기록
  visit[index] = 1;
  //주위 노드를 연결하는 버텍스들을 고려 dist배열내의 값을 비교하여 노드까지의 최단거리를 측정
  for (int i = 0; i < nrr[index].vchild.size(); i++) {
  if (nrr[index].vchild[i].value + dist[index] < dist[nrr[index].vchild[i].index]) {
  dist[nrr[index].vchild[i].index] = nrr[index].vchild[i].value + dist[index];
  }
  }
  //최단거리의 버텍스를 타고들어감
  for (int i = 0; i < nrr[index].vchild.size(); i++) {
  if (visit[nrr[index].vchild[i].index] == 0) {//방문하지 않은 노드여야 타고들어간다
  dij(nrr, nrr[index].vchild[i].index);
  }
  }

  }*/
void dijik(int n, int*visit, int*dist, node*nrr) {
	int min, v;
	for (int i = 1; i <= n; i++)
	{
		min = inf;

		for (int j = 1; j <= n; j++)
		{
			if (visit[j] == 0 && min > dist[j])
			{
				min = dist[j];
				v = j;
			}
		}

		visit[v] = 1;

		for (int j = 0; j <nrr[v].vchild.size(); j++)
		{
			if (dist[nrr[v].vchild[j].index] > dist[v] + nrr[v].vchild[j].value)
				dist[nrr[v].vchild[j].index] = dist[v] + nrr[v].vchild[j].value;
		}
	}
}
int main() {
	int n, m;

	scanf("%d", &n);
	scanf("%d", &m);

	node* nodrr = new node[n + 1];

	for (int i = 0; i < m; i++) {//초기 input
		int from, to, weight;

		scanf("%d", &from);
		scanf("%d", &to);
		//scanf("%d", &weight);
		line li;//버텍스 객체생성
		li.index = to;//향하는 인덱스
		li.value = 1;//가중치
		line pi;
		pi.index = from;
		pi.value = 1;
		nodrr[from].child.push(li);//우선순위큐에 넣는다
		nodrr[to].child.push(pi);


	}
	//우선순위 큐에있는 값들을 벡터베열로 옮겨담는다 우선순위큐가 인덱스로써 접근이 힘들어서 그럼..;;
	for (int i = 1; i <= n; i++) {
		while (!nodrr[i].child.empty()) {//우선순위 큐가 빌때까지 옮겨담는다
			nodrr[i].vchild.push_back(nodrr[i].child.top());
			nodrr[i].child.pop();
		}
	}

	int *result = new int[n + 1];

	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
		dist[i] = inf;//초기화
	}


	for (int i = 1; i <= n; i++) {
		dist[i] = 0;
		int temp = 0;
		dijik(n, visit, dist, nodrr);
		for (int k = 1; k <= n; k++) {
			temp += dist[k];

		}
		result[i] = temp;
		for (int i = 1; i <= n; i++) {
			visit[i] = 0;
			dist[i] = inf;//초기화
		}

	}
	int p=99999999;
	int q;
	for (int i = 1; i <= n; i++) {
		if (result[i] < p) {
			p = result[i];
			q = i;
		}
	}

	cout << q;
	



}





