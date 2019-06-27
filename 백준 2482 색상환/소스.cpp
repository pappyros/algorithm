#include<iostream>
using namespace std;
long long int trr[1001][1001];

long long int func(int f, int k) {
	if (trr[f][k] != 0)return trr[f][k];
	else if ((k-1)*2 > f||f==0||k==0) { 
		trr[f][k] = 0;
		return 0; }
	else {
		long long int temp =(func(f - 1, k) + func(f - 2, k - 1))%1000000003;
		trr[f][k] = temp;
	}
	return trr[f][k];
}

int main() {
	int n, t;
	trr[1][1] = 1; trr[2][1] = 2; trr[3][1] = 3; trr[4][1] = 4; trr[3][2] = 1; trr[4][2] = 3; trr[5][3] = 1; trr[6][3] = 4;
	for (int i = 1; i <= 1000; i++)trr[i][1] = i;
	cin >> n >> t;
	if (t == 1) {
		cout << n;
	}
	else {
		cout << (func(n - 1, t) + func(n - 3, t - 1)) % 1000000003;
	}
}
