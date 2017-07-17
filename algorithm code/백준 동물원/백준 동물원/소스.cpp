#include<iostream>

using namespace std;

int main() {
	int n;
	cin >> n;
	int arr[100001];
	arr[0] = 1;
	arr[1] = 3;
	for (int i = 2; i <= n; i++) {
		arr[i] = ((2 * arr[i - 1])%9901 + (arr[i - 2])%9901)%9901;

	}
	cout << arr[n];

}