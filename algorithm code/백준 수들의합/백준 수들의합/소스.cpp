#include<iostream>
using namespace std;

int main() {
	long long int n;
	cin >> n;
	long long int result = 1;

	while (true) {
		if ((result*(result + 1)) / 2 <= n) {

			result++;
		}
		else {
			break;
		}
	}
	cout << result - 1;


}