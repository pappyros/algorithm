#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;
int got = -1;
int oh[1001];
class node {
public:
	int visit = 0;
	vector<int> child;
	
};
void fffff(node *nrr,int index) {
	nrr[index].visit = 1;
	oh[index] = 1;
	
	
		for (int i = 0; i < nrr[index].child.size(); i++) {
			if (oh[nrr[index].child[i]]!= 1) {
				fffff(nrr, nrr[index].child[i]);
				
			}

		}
	
	nrr[index].visit = 0;


}
int main() {

	int num;
	//cin >> num;
	scanf("%d", &num);
	int rel;
	node*nrr = new node[num + 1];
	scanf("%d", &rel);
	for (int i = 0; i < rel; i++) {
		int pa, ch;
		scanf("%d%d", &pa,&ch);
		//cin >> pa >> ch;
		nrr[pa].child.push_back(ch);
		nrr[ch].child.push_back(pa);
	}
	
	int count = 0;
	for (int i = 1; i <= num; i++) {
		if (oh[i] != 1) {
			count++;
			fffff(nrr, i);
		}
	}

	printf("%d", count);




}