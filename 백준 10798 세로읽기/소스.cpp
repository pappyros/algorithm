#include<iostream>
#include<string>
using namespace std;
int main() {
	string str[5]; int le = 0;
	for (int i = 0; i < 5;i++) {
		cin >> str[i]; if (str[i].size() >= le)le = str[i].size();
	}
	for (int i = 0; i < 5; i++) {
		for (int k = 0; k < le; k++)str[i] += ' ';
	}
	for (int i = 0; i < le; i++) {
		for (int k = 0; k < 5; k++) {
			if (str[k][i] != ' ')cout << str[k][i];
		}
	}
}
