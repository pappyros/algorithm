#include<iostream>
#include<string>
using namespace std;

int main() {

	string a, b;
	cin >> a;
	cin >> b;
	long long int sum1 = 0;
	long long int sum2 = 0;

	for (int i = 0; i < a.length(); i++) {
		sum1 += atoi((a.substr(i, 1)).c_str());
	}
	for (int i = 0; i < b.length(); i++) {
		sum2 += atoi((b.substr(i, 1)).c_str());
	}
	long long int result = sum1 * sum2;
	cout << result;
}