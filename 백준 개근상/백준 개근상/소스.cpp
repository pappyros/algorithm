#include<iostream>

using namespace std;
int main() {
	int n;
	cin >> n;
	int**arr = new int*[6];
	//O->�⼮ L->���� A->�Ἦ
	arr[0] = new int[n];
	arr[1] = new int[n];
	arr[2] = new int[n];
	arr[3] = new int[n];
	arr[4] = new int[n];
	arr[5] = new int[n];
	arr[0][0] = 1;
	arr[1][0] = 1;
	arr[2][0] = 1;
	arr[3][0] = 0;
	arr[4][0] = 0;
	arr[5][0] = 0;
	for (int i = 1; i < n; i++) {
		//����
		arr[0][i] = arr[0][i - 1]%1000000;
		arr[0][i] += arr[2][i - 1] % 1000000;
		arr[0][i] += arr[3][i - 1] % 1000000;
		//���� ��1
		arr[1][i] = arr[0][i - 1] % 1000000;
		arr[1][i] += arr[1][i - 1] % 1000000;
		arr[1][i] += arr[2][i - 1] % 1000000;
		arr[1][i] += arr[3][i - 1] % 1000000;
		arr[1][i] += arr[4][i - 1] % 1000000;
		arr[1][i] += arr[5][i - 1] % 1000000;
		//��0��1
		arr[2][i] = arr[0][i - 1] % 1000000;
		//��0��2
		arr[3][i] = arr[2][i - 1] % 1000000;
		//��1��1
		arr[4][i] = arr[1][i - 1] % 1000000;
		//��1��2
		arr[5][i] = arr[4][i - 1] % 1000000;

	}

	cout << (arr[0][n - 1]+ arr[1][n - 1]+ arr[2][n - 1]+ arr[3][n - 1] + arr[4][n - 1] + arr[5][n - 1]) % 1000000;
	
}