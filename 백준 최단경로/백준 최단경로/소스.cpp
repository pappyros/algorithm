
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
	bool operator > (const line& rhs) const { return (value > rhs.value); };//�켱����ť �������

};
class node {

public:

	//priority_queue<line, vector<line>, greater<line>>child;//child�� ���� ���� ���߿� �Ʒ��� vchild�� �Űܴ�������
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

	for (int i = 0; i < m; i++) {//�ʱ� input
		int from, to, weight;

		scanf("%d", &from);
		scanf("%d", &to);
		scanf("%d", &weight);
		line li;//���ؽ� ��ü����
		li.index = to;//���ϴ� �ε���
		li.value = weight;//����ġ
		nodrr[from].vchild.push_back(li);
		//nodrr[from].child.push(li);//�켱����ť�� �ִ´�


	}
	//�켱���� ť���ִ� ������ ���ͺ����� �Űܴ�´� �켱����ť�� �ε����ν� ������ ���� �׷�..;;
	/*
	for (int i = 1; i <= n; i++) {
		while (!nodrr[i].child.empty()) {//�켱���� ť�� �������� �Űܴ�´�
			nodrr[i].vchild.push_back(nodrr[i].child.top());
			nodrr[i].child.pop();
		}
	}*/

	int *result = new int[n + 1];

	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
		heap[i] = inf;//�ʱ�ȭ
	}


	


	dist[st] = 0;//������ġ�� �ִܰŸ��� 0
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





