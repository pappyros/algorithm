#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	int * arr = new int[tc];
	for (int i = 0; i < tc; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + tc);
	cout << arr[0] * arr[tc - 1];


}