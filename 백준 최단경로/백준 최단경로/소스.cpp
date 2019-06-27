
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#pragma warning(disable:4996)
#define inf 99999999;
//ios::sync_with_stdio(false);
using namespace std;

class dista {
public:
	int distance;
	bool operator > (const dista& rhs) const { return (distance > rhs.distance); };
	

};

int visit[20001];

class line {
public:
	int index, value;
	bool operator > (const line& rhs) const { return (value > rhs.value); };//우선순위큐 대소조건

};
class node {

public:

	//priority_queue<line, vector<line>, greater<line>>child;//child에 쌓인 값을 나중에 아래의 vchild로 옮겨담을거임
	vector<line>vchild;

};
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
	int n, m, st;

	scanf("%d", &n);
	scanf("%d", &m);
	scanf("%d", &st);
	node* nodrr = new node[n + 1];
	priority_queue<dista, vector<dista>, greater<dista>>heap;
	for (int i = 0; i <= 20001; i++) {
		dista d;
		d.distance = 999999999;
		heap.push(d);
	}

	for (int i = 0; i < m; i++) {//초기 input
		int from, to, weight;

		scanf("%d", &from);
		scanf("%d", &to);
		scanf("%d", &weight);
		line li;//버텍스 객체생성
		li.index = to;//향하는 인덱스
		li.value = weight;//가중치
		nodrr[from].vchild.push_back(li);
		//nodrr[from].child.push(li);//우선순위큐에 넣는다


	}
	//우선순위 큐에있는 값들을 벡터베열로 옮겨담는다 우선순위큐가 인덱스로써 접근이 힘들어서 그럼..;;
	/*
	for (int i = 1; i <= n; i++) {
		while (!nodrr[i].child.empty()) {//우선순위 큐가 빌때까지 옮겨담는다
			nodrr[i].vchild.push_back(nodrr[i].child.top());
			nodrr[i].child.pop();
		}
	}*/

	int *result = new int[n + 1];

	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
		heap[i] = inf;//초기화
	}


	


	dist[st] = 0;//시작위치의 최단거리는 0
	dijik(n, visit, dist, nodrr);



	for (int i = 1; i <= n; i++) {
		result[i] = dist[i];
	}

	int dap;
	for (int i = 1; i <= n; i++) {
		if (result[i] >= 9999999) {
			printf("INF\n");
			
		}
		else {
			printf("%d\n", result[i]);
			
		}
	}
	



}





