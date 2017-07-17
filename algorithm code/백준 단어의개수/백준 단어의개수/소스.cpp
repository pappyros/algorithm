#include<iostream>
#include<string>
using namespace std;

int main() {

	string aaa;
	cin >> aaa;
	int a = 0;
	for (int i = 0; i < aaa.size(); i++) {
		cout << aaa.substr(i, 1);
		if (aaa.substr(i, 1) == " ") {
			
			a++;
		}
	}
	cout << a;
}