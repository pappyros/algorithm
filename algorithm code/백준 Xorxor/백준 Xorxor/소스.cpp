#include<iostream>
using namespace std;

int main() {
	int A,B, C;
	cin >> A >> B >> C;
	int result;
	for (int i = 0; i < C; i++) {
		if (i == 0) {
			result = A ^ B;
			continue;
		}
		result = result^B;
	}
	cout << result;
}