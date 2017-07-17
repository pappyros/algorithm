#include<iostream>
using namespace std;
int max(int a, int b) {
	if (a > b) {
		return a;
	}
	else {
		return b;
	}
}
int func(int **arr, int **mrr,int st,int n) {
	if (st == 1) {
		for (int i = 0; i < st; i++) {
			mrr[st-1][i] = arr[st-1][i] + max(mrr[st][i], mrr[st][i + 1]);
			return mrr[st-1][i];
		}
		

	}
	else if (st == n) {
		for (int i = 0; i < st; i++) {
			mrr[st-1][i] = arr[st-1][i];
		}

	}
	else {
		for (int i = 0; i < st; i++) {
			mrr[st-1][i] =arr[st-1][i]+ max(mrr[st][i], mrr[st][i + 1]);
		}
	}
	func(arr, mrr, st - 1, n);

}


int main() {
	int n;
	cin >> n;
	int **arr = new int*[n];
	int **mrr = new int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[i + 1];
		for (int k = 0; k < i + 1; k++) {
			cin >> arr[i][k];
		}
	}
	for (int i = 0; i < n; i++) {
		mrr[i] = new int[i + 1];
		for (int k = 0; k < i + 1; k++) {
			mrr[i][k] = 0;
		}
	}

	cout << func(arr, mrr, n, n);


	
}