#include<iostream>
#include<vector>
#include<queue>
using namespace std;

int main() {
	int n;
	cin >> n;
	vector<int>arr;
	vector<int>result;
	for (int i = 1; i <= n; i++) {
		arr.push_back(i);
	}
	int start = 1;
	while (arr.size() != 1) {
		if (start == 1) {
			int k = arr[0];
			result.push_back(k);
			arr.erase(arr.begin());

			start = 2;

		}
		else {
			int k = arr[0];
			arr.push_back(k);
			arr.erase(arr.begin());
			

			start = 1;
		}
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i]<<" ";
	}
	cout << arr[0];

}

