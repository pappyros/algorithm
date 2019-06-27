#include<iostream>
#include<vector>
#include<algorithm>

using namespace std;

bool func(int a, int b) {
	return a > b;
}

int main() {

	int n;
	cin >> n;
	int *arr = new int[n];
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<int> max;
	max.push_back(0);
	for (int i = 0; i < n; i++) {
		if (i == 0) {
			max.push_back(arr[i]);
			continue;
		}
		int imsi = 0;
		for (int k = 0; k <= i; k++) {
			if (arr[i - k] + max[k] > imsi) {
				imsi = arr[i - k] + max[k];
			}
		}
		max.push_back(imsi);
		

	}
	cout << max[n];
}