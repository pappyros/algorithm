#include<iostream>
#include<algorithm>
using namespace std;
int main() {

	int num;
	cin >> num;
	int*arr = new int[num];
	int*one = new int[num];
	int*two = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	for (int i = 0; i < num; i++) {
		if (i == 0) {
			one[i] = arr[i];
			two[i] = 0;
			continue;
		}
		else if (i == 1) {
			one[i] = one[i - 1] + arr[i];
			two[i] = arr[i];
			continue;
		}
		one[i] = arr[i] + two[i - 1];
		two[i] = arr[i] + max(one[i - 2], two[i - 2]);
	}
	cout << max(one[num - 1], two[num - 1]);
}