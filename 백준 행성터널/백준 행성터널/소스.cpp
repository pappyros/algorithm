#include<iostream>
#include<vector>
#include<algorithm>
#include<queue>
#include<functional>
#include<cmath>
#pragma warning(disable:4996)


using namespace std;
int visit[100001];
int sum = 0;

class line {
public:
	int to, weight;
	bool operator > (const line& rhs) const { return (weight > rhs.weight); };
};

class node {
public:
	int x, y, z;

};

void func(node*nrr, int total,int n) {
	int v = 1;
	total--;
	

	while (total--) {
		visit[v] = 1;
		int ppp;
		int weig = 1999999999;
		for (int k = 1; k <=n ; k++) {
			
			if (visit[k] != 1) {
				
				int weight = min(abs(nrr[v].x - nrr[k].x), min(abs(nrr[v].y - nrr[k].y), abs(nrr[v].z - nrr[k].z)));
				if (weig > weight) {
					weig = weight;
					ppp = k;
				}

			}
		}
		sum += weig;
		v = ppp;
		

	}
}

int main() {

	int n;
	
	scanf("%d", &n);
	node* nrr = new node[n + 1];
	
	
	for (int i = 1; i <= n; i++) {
		scanf("%d%d%d", &nrr[i].x, &nrr[i].y, &nrr[i].z);
	}
	
	for (int i = 1; i <= n; i++) {
		visit[i] = 0;
	}
	func(nrr, n,n);
	printf("%d", sum);

}
