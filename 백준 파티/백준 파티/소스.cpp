
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#define inf 99999999;
using namespace std;
int dist[20001];
int visit[20001];

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
void dijik(int n,int*visit,int*dist,node*nrr) {
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
	node* nodrr = new node[n+1];

	for (int i = 0; i < m; i++) {//�ʱ� input
		int from, to, weight;
		
		scanf("%d", &from);
		scanf("%d", &to);
		scanf("%d", &weight);
		line li;//���ؽ� ��ü����
		li.index = to;//���ϴ� �ε���
		li.value = weight;//����ġ
		nodrr[from].child.push(li);//�켱����ť�� �ִ´�
		

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
		
		dijik(n, visit, dist, nodrr);
		result[i] = dist[st];
		for (int i = 1; i <= n; i++) {
			visit[i] = 0;
			dist[i] = inf;
		}
	    
	}
	
	
	dist[st] = 0;//������ġ�� �ִܰŸ��� 0
	dijik(n, visit, dist, nodrr);
	
	
	
	for (int i = 1; i <= n; i++) {
		result[i] = result[i]+dist[i];
	}
	
	int dap;
	for (int i = 1; i <= n; i++) {
		if (i == 1) {
			dap = result[i];
			continue;
	}
		if (result[i] > dap) {
			dap = result[i];
		}
	}
	cout << dap;
	


}





