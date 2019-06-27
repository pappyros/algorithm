#include<iostream>
#include<vector>
#include<string>
#include<algorithm>
using namespace std;
int arr[1001][1001]; string str1, str2; vector<char>dap;
void func(int y, int x) {
	if (x == -1 || y == -1)return;
	if (arr[y][x] > arr[y - 1][x - 1] && arr[y][x] > arr[y - 1][x] && arr[y][x] > arr[y][x - 1]) {
		dap.push_back(str2[y - 1]); func(y - 1, x - 1);
	}
	else if (arr[y][x] == arr[y - 1][x]) {
		func(y - 1, x);
	}
	else if (arr[y][x] == arr[y][x - 1]) {
		func(y, x - 1);
	}
}
int main() {
	 cin >> str1 >> str2; int size1 = str1.size(); int size2 = str2.size();
	for (int i = 1; i <= size2; i++) {
		for (int k = 1; k <= size1; k++)arr[i][k] = (str1[k - 1] == str2[i - 1] ? arr[i - 1][k - 1] + 1 : max(arr[i][k - 1], arr[i - 1][k]));
	}cout << arr[size2][size1]<<endl;
	int cnt = 1;
	func(size2, size1);
	for (int i = dap.size()-1; i >= 0; i--) {
		cout << dap[i];
	}
	
}
