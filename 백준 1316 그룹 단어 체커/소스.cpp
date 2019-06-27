#include<iostream>
#include<string>
using namespace std;
bool arr[26];
int toas(char c) {
	return (int)(c - 97);
}
int main() {
	int n; cin >> n; int dap = 0;
	for (int i = 0; i < n; i++) {
		string str; cin >> str; bool ha = true; int size = str.size();

		for (int k = 0; k < size; k++) {
			if (arr[toas(str[k])] == false || str[k] == str[k - 1])arr[toas(str[k])] = true;
			else { ha = false; break; }
		}
		if (ha)dap++;fill(arr, arr + 26, false);
	}cout << dap;
}
