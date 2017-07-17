#include<iostream>
using namespace std;

int main() {
	int n;
	cin >> n;
	long long int **arr = new long long int*[10];
	for (int i = 0; i < 11; i++) {
		arr[i] = new long long int[n];
		arr[i][0] = 1;
		
	}
	arr[9][0] = 0;
	for (int i = 1; i < n; i++) {
		for (int k = 0; k < 10; k++) {
			if(k==0){
				arr[k][i] = (arr[k +1][i - 1]%1000000000+arr[9][i-1]%1000000000)%1000000000;
			}
			else if (k == 9) {
				arr[k][i] = arr[0][i - 1];

			}
			else if (k == 8) {
				arr[k][i] = arr[k - 1][i - 1];
			}
			else {
				arr[k][i] = (arr[k - 1][i - 1]%1000000000 + arr[k + 1][i - 1]%1000000000)%1000000000;
			}
		}
	}
	long long int sum = 0;
	for (int i = 0; i < 10; i++) {
		sum= (arr[i][n - 1]+sum)%1000000000;
	}
	cout << sum;
}