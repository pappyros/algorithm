#include<iostream>
#include<vector>
#pragma warning(disable:4996)
using namespace std;

int sum = 0;
class node {
public:
	int in, out;
	int visit = 0;
};
int func(node *nrr, int *insa, int index) {
	
	if (insa[index] == -1) {
		return -1;
	}



	if (nrr[index].visit == 1) {//²¿¸®¸¦ ¹°¾ù´Ù
		insa[index] = 1;
		nrr[index].visit = 0;
		return index;
	}
	else {
		nrr[index].visit = 1;
		int sel = func(nrr, insa, nrr[index].out);
		if (sel == -1) {//³Ê¾Æ½Î ¤»¤»
			insa[index] = -1;
			sum++;
			nrr[index].visit = 0;
			return -1;

		}
		else if (index == sel) {//¿©±â±îÁö ÀÎ½Î
			insa[index] = 1;
			nrr[index].visit = 0;
			return -1;//¾ÕÀ¸·Î¾Æ½Î;
		}
		else {
			insa[index] = 1;
			nrr[index].visit = 0;
			return sel;
		}

	}

}


int main() {
	int t;
	scanf("%d", &t);
	int*result = new int[t];
	for (int q = 0; q < t; q++) {
		int n;
		scanf("%d", &n);
		node *nrr = new node[n + 1];
		int *insa = new int[n + 1];
		for (int i = 1; i <= n; i++) {
			insa[i] = 0;
			int a;
			scanf("%d", &a);
			nrr[i].out = a;
			nrr[a].in = i;
		}
		for (int i = 1; i <= n; i++) {
			if (insa[i] == -1||insa[i] == 1)continue;
			func(nrr, insa, i);

		}

		
		result[q] = sum;
		sum = 0;
		

	}


	for (int i = 0; i < t; i++) {
		cout << result[i] << endl;
	}
	


}