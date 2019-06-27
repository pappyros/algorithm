#include<iostream>
#include<string>
using namespace std;

int main() {
	string me, doc;
	cin >> me >> doc;
	if (doc.length() > me.length()) {
		cout << "no";
	}
	else {
		cout << "go";
	}


}