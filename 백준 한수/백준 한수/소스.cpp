#include<iostream>
using namespace std;
int main() {
	int a;
	cin >> a;
	int result = 0;
	for (int i = 1; i <= a; i++) {
		if (i < 10) {
			result++;
		}
		else if (i < 100) {
			
				result++;
			
		}
		else {
			int a = i / 100;
			int b = (i % 100) / 10;
			int c = i % 10;
			if (c-b==b-a) {
				result++;
			}

		}
	}
	cout << result;


}