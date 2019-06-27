#include<iostream>
#include<string>
using namespace std;
int main() {
	string A;
	string result = "";
	cin >> A;
	if (A.length() % 3 == 1) {
		A = "00" + A;
	}
	else if (A.length() % 3 == 2) {
		A = "0" + A;
	}

	for (int i = 0; i < A.length(); i=i+3) {
		int aaa = atoi(A.substr(i, 1).c_str())*4 + atoi(A.substr(i + 1, 1).c_str())*2 + atoi(A.substr(i + 2, 1).c_str());
		result += to_string(aaa);
	}
	cout << result;
}