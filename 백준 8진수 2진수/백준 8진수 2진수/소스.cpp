#include<iostream>
#include<string>;
using namespace std;

int main() {
	string oct;
	cin >> oct;
	if (oct != "0") {
		string dab = "";
		for (int i = 0; i < oct.size(); i++) {
			if (i == 0) {
				if (oct.substr(i, 1) == "1") {
					dab += "1";
				}
				if (oct.substr(i, 1) == "2") {
					dab += "10";
				}
				if (oct.substr(i, 1) == "3") {
					dab += "11";
				}
				if (oct.substr(i, 1) == "4") {
					dab += "100";
				}
				if (oct.substr(i, 1) == "5") {
					dab += "101";
				}
				if (oct.substr(i, 1) == "6") {
					dab += "110";
				}
				if (oct.substr(i, 1) == "7") {
					dab += "111";
				}





				continue;
			}

			if (oct.substr(i, 1) == "1") {
				dab += "001";
			}
			if (oct.substr(i, 1) == "2") {
				dab += "010";
			}
			if (oct.substr(i, 1) == "3") {
				dab += "011";
			}
			if (oct.substr(i, 1) == "4") {
				dab += "100";
			}
			if (oct.substr(i, 1) == "5") {
				dab += "101";
			}
			if (oct.substr(i, 1) == "6") {
				dab += "110";
			}
			if (oct.substr(i, 1) == "7") {
				dab += "111";
			}
			if (oct.substr(i, 1) == "0") {
				dab += "000";
			}

		}
		cout << dab;
	}
	else {
		cout << 0;
	}
}