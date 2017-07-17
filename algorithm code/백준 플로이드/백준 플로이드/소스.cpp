
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
	bool operator > (const line& rhs) const { return (value > rhs.value); };//�켱����ť �������

};
class node {

public:

	priority_queue<line, vector<line>, greater<line>>child;//child�� ���� ���� ���߿� �Ʒ��� vchild�� �Űܴ�������
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
  //�ϴ� ������� ���
  visit[index] = 1;
  //���� ��带 �����ϴ� ���ؽ����� ��� dist�迭���� ���� ���Ͽ� �������� �ִܰŸ��� ����
  for (int i = 0; i < nrr[index].vchild.size(); i++) {
  if (nrr[index].vchild[i].value + dist[index] < dist[nrr[index].vchild[i].index]) {
  dist[nrr[index].vchild[i].index] = nrr[index].vchild[i].value + dist[index];
  }
  }
  //�ִܰŸ��� ���ؽ��� Ÿ���
  for (int i = 0; i < nrr[index].vchild.size(); i++) {
  if (visit[nrr[index].vchild[i].index] == 0) {//�湮���� ���� ��忩�� Ÿ�����
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

	for (int i = 0; i < m; i++) {//�ʱ� input
		int from, to, weight;

		scanf("%d", &from);
		scanf("%d", &to);
		//scanf("%d", &weight);
		line li;//���ؽ� ��ü����
		li.index = to;//���ϴ� �ε���
		li.value = 1;//����ġ
		line pi;
		pi.index = from;
		pi.value = 1;
		nodrr[from].child.push(li);//�켱����ť�� �ִ´�
		nodrr[to].child.push(pi);


	}
	//�켱���� ť���ִ� ������ ���ͺ����� �Űܴ�´� �켱����ť�� �ε����ν� ������ ���� �׷�..;;
	for (int i = 1; i <= n; i++) {
		while (!nodrr[i].child.empty()) {//�켱���� ť�� �������� �Űܴ�´�
			nodrr[i].vchild.push_back(nodrr[i].child.top());
			nodrr[i].child.pop();
		}
	}

	int *result = new int[n + 1];

	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
		dist[i] = inf;//�ʱ�ȭ
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
			dist[i] = inf;//�ʱ�ȭ
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





