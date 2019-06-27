#include<iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	int * arr = new int[a];
	arr[0] = 1;
	arr[1] = 2;
	for (int i = 2; i < a; i++) {
		arr[i] = arr[i - 1]%10007 + arr[i - 2]%10007;
		arr[i] = arr[i] % 10007;
	}
	cout << arr[a - 1];
}