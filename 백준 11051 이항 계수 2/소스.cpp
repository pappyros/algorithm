#include<iostream>
using namespace std;
int arr[1001][1001];
int main() {
	int n, k; cin >> n >> k;
	for (int i = 0; i <= 1000; i++)arr[i][0] = 1;
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= i; k++)arr[i][k] = (arr[i - 1][k - 1] + arr[i - 1][k])%10007;
	}cout << arr[n][k];
}
