#include<iostream>
#include<vector>
using namespace std;
long long int arr[31][31];
long long int func(int a, int b) {
	if (arr[a][b] != 0)return arr[a][b];
	if (a == 0) {
		arr[a][b] = 1; return 1;
	}
	else if (b == 0) {
		long long int temp =func(a - 1, b + 1);
		arr[a][b] = temp;
		return temp;
	}
	else {
		long long int temp = func(a - 1, b + 1) + func(a, b - 1);
		arr[a][b] = temp;
		return temp;
	}
}
int main() {
	vector<int>vrr;
	while (true) {
		int tp; cin >> tp;
		if (tp == 0)break; vrr.push_back(tp);
	}
	for (int i = 0; i < vrr.size(); i++) {
		cout << func(vrr[i], 0) << endl;
	}
}
