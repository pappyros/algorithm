#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int ctp;
	cin >> ctp;
	int a, b, part;
	cin >> a >> b;
	part = a*b;
	int *arr = new int [ctp];
	for (int i = 0; i < ctp; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + ctp);
	int sum = 0;
	for (int i = ctp-1; i >=-1; i--) {
		if (i == -1) {
			cout << "STRESS";
			break;
		}
		sum += arr[i];
		if (sum >= part) {
			cout << ctp - i;
			break;
		}
	}
}