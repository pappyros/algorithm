#include <iostream>
using namespace std;

int main() {
	
	// 변수 선언부
	int n;
	int arr[1001][10];
	int rlt = 0;

	// 초기화부
	cin >> n;
	for (int i = 0; i < 10; i++)
		arr[1][i] = 1;

	// Algorithm
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 10; j++) {
			for (int k = 0; k <= j; k++) {
				arr[i][j] += arr[i - 1][k];
				arr[i][j] %= 10007;
			}
		}
	}

	for (int i = 0; i < 10; i++) {
		rlt += arr[n][i];
		rlt %= 10007;
	}

	// 결과출력 
	cout << rlt;

	return 0;
}