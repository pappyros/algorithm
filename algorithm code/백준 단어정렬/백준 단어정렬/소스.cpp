#include<iostream>
#include<string>
#include<algorithm>
using namespace std;

int main() {
	int num;
	cin >> num;
	string *arr = new string[num];
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + num);

	for (int i = 1; i <= 50; i++) {
		for (int k = 0; k < num; k++) {
			if (arr[k].size() == i&&k>0) {
				if (arr[k - 1] != arr[k]) {
					cout << arr[k] << endl;
				}
			}
			else if (arr[k].size()==i) {
				cout << arr[k] << endl;
			}
		}
	}

}