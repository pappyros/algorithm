#include<iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	char**arr = new char*[a];
	for (int i = 0; i < a; i++) {
		arr[i] = new char[b];
		cin >> arr[i];
	}
	char x, y, z, w;
	x = arr[0][0];
	y = arr[0][b - 1];
	z = arr[a - 1][0];
	w = arr[a - 1][b - 1];
	int M;
	if (a > b) {
		M = b;
	}
	else {
		M = a;
	}

	int result=0;

	for (int i = 0; i < M; i++) {
		for (int k = 0; k < a - i; k++) {
			for (int q = 0; q < b - i; q++) {
				if (arr[k][q] == arr[k][q + i] && arr[k + i][q] == arr[k + i][q + i]&&arr[k][q]==arr[k+i][q] ) {
					result = (i+1)*(i+1);

				}
			}
		}

	}

	cout << result;

}