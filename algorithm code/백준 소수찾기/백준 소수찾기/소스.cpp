#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int> arr;
	
	int a;
	cin >> a;
	for (int i = 0; i < a; i++) {
		int b;
		cin >> b;
		arr.push_back(b);
	}
	int num = 0;
	for (int i = 0; i < a; i++) {
		if (arr[i]==1) {
			num++;
			continue;

		}
		for (int k = arr[i] - 1; k > 1; k--) {
			if (arr[i] % k == 0) {
				num++;
				break;
			}
		}
	}
	cout << a-num;




}

