
#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#pragma warning(disable:4996)
#define inf 99999999;
using namespace std;
int dist[1000000];
int visit[1000000];

class line {
public:
	int index, value;
	bool operator > (const line& rhs) const { return (value > rhs.value); };//�켱����ť �������

};
class node {

public:

	priority_queue<line, vector<line>, greater<line>>child;//child�� ���� ���� ���߿� �Ʒ��� vchild�� �Űܴ�������
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
	int n, m;

	scanf("%d", &n);
	scanf("%d", &m);
	
	node* nodrr = new node[n*m+10000];
	char**arr = new char*[m+100];
	for (int i = 1; i <= m; i++) {
		arr[i] = new char[n + 100];
		cin >> arr[i]+1;
		
		
	}
	/*
	for (int i = 1; i <= m; i++) {
		for (int k = 1; k <= n; k++) {
			cout << arr[i][k];
		}
		cout << endl;

	}*/

	for (int i = 1; i <= m; i++) {//����
		for (int k = 1; k <= n; k++) {
			if (arr[i][k] == '0') {
				//��
				if (i != 1&&arr[i-1][k]==0) {
					line li;
					li.index = (i - 2)*n + k;
					li.value = 0;
					nodrr[(i - 1)*n + k].vchild.push_back(li);
					line li2;
					li2.index = (i - 1)*n + k;
					li2.value = 0;
					nodrr[(i - 2)*n + k].vchild.push_back(li2);
					

				}
				//��
				if (k != n&&arr[i][k+1]=='0') {
					line li;
					li.index = (i - 1)*n + k+1;
					li.value = 0;
					nodrr[(i - 1)*n + k].vchild.push_back(li);
					line li2;
					li2.index = (i - 1)*n + k;
					li2.value = 0;
					nodrr[(i - 1)*n + k + 1].vchild.push_back(li2);

				}
				//��
				if (k != 1&&arr[i][k-1]=='0') {
					line li;
					li.index = (i - 1)*n + k -1;
					li.value = 0;
					nodrr[(i - 1)*n + k].vchild.push_back(li);
					line li2;
					li2.index = (i - 1)*n + k;
					li2.value = 0;
					nodrr[(i - 1)*n + k -1].vchild.push_back(li2);

				}
				//��
				if (i != m&&arr[i+1][k]=='0') {
					line li;
					li.index = (i)*n + k;
					li.value = 0;
					nodrr[(i - 1)*n + k].vchild.push_back(li);
					line li2;
					li2.index = (i - 1)*n + k;
					li2.value = 0;
					nodrr[i*n+k].vchild.push_back(li2);

				}
			}
			else {//1��
				  //��
				if (i != 1) {
					if (arr[i - 1][k] == '1') {
						line li;
						li.index = (i - 2)*n + k;
						li.value = 1;
						nodrr[(i - 1)*n + k].vchild.push_back(li);
						line li2;
						li2.index = (i - 1)*n + k;
						li2.value = 1;
						nodrr[(i - 2)*n + k].vchild.push_back(li2);

					}
					else {
						line li;
						li.index = (i - 2)*n + k;
						li.value = 0;
						nodrr[(i - 1)*n + k].vchild.push_back(li);
						line li2;
						li2.index = (i - 1)*n + k;
						li2.value = 1;
						nodrr[(i - 2)*n + k].vchild.push_back(li2);

					}
					
						
					


				}
				//��
				if (k != n) {
					if (arr[i][k+1]=='1') {
						line li;
						li.index = (i - 1)*n + k + 1;
						li.value = 1;
						nodrr[(i - 1)*n + k].vchild.push_back(li);
						line li2;
						li2.index = (i - 1)*n + k;
						li2.value = 1;
						nodrr[(i - 1)*n + k + 1].vchild.push_back(li2);

					}
					else {
						line li;
						li.index = (i - 1)*n + k + 1;
						li.value = 0;
						nodrr[(i - 1)*n + k].vchild.push_back(li);
						line li2;
						li2.index = (i - 1)*n + k;
						li2.value = 1;
						nodrr[(i - 1)*n + k + 1].vchild.push_back(li2);

					}
					

				}
				//��
				if (k != 1) {
					if (arr[i][k - 1] == '1') {
						line li;
						li.index = (i - 1)*n + k - 1;
						li.value = 1;
						nodrr[(i - 1)*n + k].vchild.push_back(li);
						line li2;
						li2.index = (i - 1)*n + k;
						li2.value = 1;
						nodrr[(i - 1)*n + k - 1].vchild.push_back(li2);

					}
					else {
						line li;
						li.index = (i - 1)*n + k - 1;
						li.value = 0;
						nodrr[(i - 1)*n + k].vchild.push_back(li);
						line li2;
						li2.index = (i - 1)*n + k;
						li2.value = 1;
						nodrr[(i - 1)*n + k - 1].vchild.push_back(li2);

					}
					
				}
				//��
				if (i != m) {
					if (arr[i+1][k] == '1') {
						line li;
						li.index = (i)*n + k;
						li.value = 1;
						nodrr[(i - 1)*n + k].vchild.push_back(li);
						line li2;
						li2.index = (i - 1)*n + k;
						li2.value = 1;
						nodrr[i*n + k].vchild.push_back(li2);

					}
					else {
						line li;
						li.index = (i)*n + k;
						li.value = 0;
						nodrr[(i - 1)*n + k].vchild.push_back(li);
						line li2;
						li2.index = (i - 1)*n + k;
						li2.value = 1;
						nodrr[i*n + k].vchild.push_back(li2);

					}
					

				}

			}
		}
	}
	
	/*
	for (int i = 1; i <= m; i++) {
		for (int k = 1; k <= n; k++) {
			for (int p = 0; p < nodrr[(i - 1)*n + k].vchild.size(); p++) {
				cout << "�ε���" << nodrr[(i - 1)*n + k].vchild[p].index << "��" << nodrr[(i - 1)*n + k].vchild[p].value;
			}
			cout << endl;
			
		}
	}*/

	for (int i = 1; i <= n*m+10000; i++) {
		visit[i] = 0;
		dist[i] = inf;//�ʱ�ȭ
	}




	dist[1] = 0;//������ġ�� �ִܰŸ��� 0
	dijik(n*m, visit, dist, nodrr);



	
	cout << dist[n*m];



}





