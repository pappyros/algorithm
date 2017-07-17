#include<iostream>
#include<algorithm>
using namespace std;

int main() {

	int n;
	cin >> n;
	int *result = new int[n];
	for (int i = 0; i < n; i++) {
		int get;
		cin >> get;
		int **arr = new int*[2];
		arr[0] = new int[get];
		arr[1] = new int[get];
		for (int k = 0; k < get; k++) {
			cin >> arr[0][k];
		}
		for (int k = 0; k < get; k++) {
			cin >> arr[1][k];
		}

		int **brr = new int*[3];
		brr[0] = new int[get];
		brr[1] = new int[get];
		brr[2] = new int[get];
		brr[0][0] = arr[0][0];
		brr[1][0] = arr[1][0];
		brr[2][0] = 0;
		for (int k = 1; k < get; k++) {
			brr[0][k] = arr[0][k] + max(brr[1][k - 1], brr[2][k - 1]);
			brr[1][k] = arr[1][k] + max(brr[0][k - 1], brr[2][k - 1]);
			brr[2][k] = max(brr[0][k - 1], brr[1][k - 1]);
		}

		result[i] = max(brr[0][get - 1], brr[1][get - 1]);
		result[i] = max(result[i], brr[2][get - 1]);




	}

	for (int i = 0; i < n; i++) {
		cout << result[i] << endl;
	}
}