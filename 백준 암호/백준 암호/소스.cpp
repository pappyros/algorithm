#include<iostream>
#include<string>
#include<cmath>

using namespace std;
int main() {
	string A, pass;
	getline(cin, A);
	cin>> pass;
	char*arr;
    arr = (char*)A.c_str();
	char*mrr;
	mrr = (char*)pass.c_str();
	for (int i = 0; i < A.length(); i++) {
		if (arr[i] == ' ') {

			continue;
		}
		if (arr[i] - mrr[i%pass.length()] > 0) {
			arr[i] = abs(arr[i] - mrr[i%pass.length()]) + 96;
		}
		else {
			int b = abs(arr[i] - mrr[i%pass.length()]);
			arr[i] = 122 - b;
		}
	}
	for (int i = 0; i < A.length(); i++) {
		cout << arr[i];
	}
	

}