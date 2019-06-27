#include<iostream>
using namespace std;

int main() {
	int a, b;
	cin >> a >> b;
	int *A = new int[a];
	int *B = new int[b];
	for (int i = 0; i < a; i++) {
		A[i] = i;
	}
	for (int i = 0; i < b; i++) {
		B[i] = i;
	}
	char **arr = new char*[a];
	for (int i = 0; i < a; i++) {
		arr[i] = new char[b];
		cin >> arr[i];
		for (int k = 0; k < b; k++) {
			if (arr[i][k] == 'X') {
				A[i] = -1;
				B[k] = -1;
			}
		}
	}
	int re1 = 0;
	int re2 = 0;
	for (int i = 0; i < a; i++) {
		if (A[i] != -1) {
			re1++;
		}
	}
	for (int i = 0; i < b; i++) {
		if (B[i] != -1) {
			re2++;
		}
	}
	if (re1 > re2) {
		cout << re1;
	}
	else {
		cout << re2;
	}

}