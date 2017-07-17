#include<iostream>
#include<string>
#include<vector>
#include<algorithm>
using namespace std;
int main() {
	int a, b;
	cin >> a >> b;
	string *arr1 = new string[a+b];
	
	vector<string> result;

	for (int i = 0; i < a; i ++) {
		cin >> arr1[i];
	}
	int sum = 0;
	for (int i = a; i < b+a; i++) {
		cin >> arr1[i];
	}
	sort(arr1, arr1 + (a + b));
	for (int i = 0; i < a+b; i++) {
		if (i == 0) {
			continue;
		}
		if (arr1[i] == arr1[i - 1]) {
			result.push_back(arr1[i]);
			sum++;
		}
	}

	cout << sum << endl;
	sort(result.begin(), result.end());
	for (int i = 0; i < result.size(); i++) {
		cout << result[i] << endl;
	}

}