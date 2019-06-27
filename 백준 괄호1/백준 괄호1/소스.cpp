#include<iostream>
#include<vector>
using namespace std;
int main() {
	int m;
	cin >> m;
	int *result = new int[m];
	for (int q = 0; q < m; q++) {
		int a;
		cin >> a;
		if (a % 2 == 1) {
			result[q] = 0;
		}
		else {
			a = a / 2;
			long long int*arr = new long long int[a + 1];
			arr[0] = 1;
			for (int k = 1; k < a + 1; k++) {
				arr[k] = 0;
			}
			for (int k = 1; k <= a; k++) {
				for (int d = 0; d <= (k - 1) / 2; d++) {
					if (d == ((k - 1) - d)) {
						arr[k] = (((arr[d] * arr[d]))%1000000007+arr[k])%1000000007;
					}
					else {
						arr[k] = (((arr[d] * arr[(k - 1) - d]) * 2)%1000000007+arr[k])%1000000007;
					}
				}
			}

			result[q] = arr[a];
		}
	}
	for (int q = 0; q < m; q++) {
		cout << result[q] << endl;
	}
}