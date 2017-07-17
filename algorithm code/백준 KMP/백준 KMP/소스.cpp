#include<iostream>
#include<string>
using namespace std;
int main() {
	char arr[100];
	cin >> arr;
	string result = "";
	for (int i = 0; i < 100; i++) {
		if (i == 0) {
			result += arr[0];
			continue;
		}
		if (arr[i] == '-') {
			result += arr[i + 1];
		}
	}
	cout << result;
}