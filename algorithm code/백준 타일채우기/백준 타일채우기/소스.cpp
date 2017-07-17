#include<iostream>
using namespace std;

int main() {

	int n;
	cin >> n;
	int *arr = new int[n + 1];
	
	for (int i = 1; i <= n; i++) {
		arr[i] = 0;
	}
	arr[2] = 3;
	for(int i = 4; i <= n; i = i + 2){

		for (int k = i-2; k >= 2; k = k - 2) {
			if (k == i-2) {
				arr[i] = arr[i]+(arr[k] * 3);
			}
			else {
				arr[i] =arr[i]+ (arr[k] * 2);
			}

		}
		arr[i] += 2;
	}

	cout << arr[n];

}