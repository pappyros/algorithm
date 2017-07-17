#include<iostream>
using namespace std;

int main() {

	int num;
	cin >> num;

	int *arr = new int[num];

	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	int result = 0;
	
	for (int i = 0; i < num; i++) {
		if (arr[i] == 0) {
			continue;
		}
		int height = arr[i];
		result++;
		for (int k = i; k < num;k++) {
			if (arr[k] == height) {
				arr[k] = 0;
				height--;
			}
		}
	}
	cout << result;

}