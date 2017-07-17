#include<iostream>

using namespace std;
int fib(int k) {
	int *arr = new int[k + 1];
	arr[1] = 1;
	arr[2] = 1;
	for (int i = 3; i <= k; i++) {
		arr[i] = arr[i - 1] + arr[i - 2];

		
	}
	return arr[k];

}
int main() {

	cout << fib(1000);

}