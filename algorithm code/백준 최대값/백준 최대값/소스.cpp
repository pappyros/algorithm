#include<iostream>
using namespace std;

int main() {
	int n = 9;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	int sum = 0;
	int num = -1;
	for (int i = 0; i < n; i++) {
		if (arr[i] >= sum) {
			sum = arr[i];
			num = i+1;
		}
	}
	cout << sum << endl;
	cout << num;
}