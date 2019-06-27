#include<iostream>
#include<cmath>
#include<string>
using namespace std;
char nrr[4] = { '2','3','5','7' };
bool func(int num) {
	bool ret = 1;
	for (int i = 2; i < num;i++) {
		if (num%i == 0) {
			ret = false; break;
		}
	}return ret;
}

void func(string str,int cu, int to) {
	if (cu == to) {
		if (func(atoi(str.c_str()))) {
			cout << str << endl;
		}
	}
	if (func(atoi(str.c_str()))) {
		for (int i = 1; i <= 9; i += 2) {
			func(str + to_string(i), cu + 1, to);
		}
	}

}

int main() {
	int n; cin >> n;
	func("2", 1, n);
	func("3", 1, n);
	func("5", 1, n);
	func("7", 1, n);
}
