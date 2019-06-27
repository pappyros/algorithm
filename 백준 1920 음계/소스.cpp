#include<iostream>
using namespace std;
int arr[8];
int main() {
	int a = 0; int b = 0;
	for (int i = 0; i < 8; i++) {
		cin >> arr[i];
		if (arr[i] == i + 1) a++;
		if (arr[i] == 8 - i) b++;
	}
	if (a == 8)cout << "ascending";
	else if (b == 8)cout << "descending";
	else cout << "mixed";
}
