#include<iostream>
#include<string>
using namespace std;

int main() {
	string result = "";
	for (int i = 0; i < 3; i++) {
		  /*black	0	1
			brown	1	10
			red	2	100
			orange	3	1000
			yellow	4	10000
			green	5	100000
			blue	6	1000000
			violet	7	10000000
			grey	8	100000000
			white	9	1000000000*/
		string s;
		cin >> s;
		if (s == "black") {
			if (i == 0) {
				
			}
			else if (i == 1 && result == "") {

			}
			else if (i == 1) {
				result += "0";
			}
			else if (i == 2) {
				
			}
		}
		else if (s == "brown") {
			if (i == 2&&result=="") {
				
			}
			else if (i == 2) {
				result += "0";
			}
			else {
				result += "1";
			}

		}
		else if (s == "red") {
			if (i == 2 && result == "") {

			}
			else if (i == 2) {
				result += "00";
			}
			else {
				result += "2";
			}

		}
		else if (s == "orange") {
			if (i == 2 && result == "") {

			}
			else if (i == 2) {
				result += "000";
			}
			else {
				result += "3";
			}

		}
		else if (s == "yellow") {
			if (i == 2 && result == "") {

			}
			else if (i == 2) {
				result += "0000";
			}
			else {
				result += "4";
			}

		}
		else if (s == "green") {
			if (i == 2 && result == "") {

			}
			else if (i == 2) {
				result += "00000";
			}
			else {
				result += "5";
			}

		}
		else if (s == "blue") {
			if (i == 2 && result == "") {

			}
			else if (i == 2) {
				result += "000000";
			}
			else {
				result += "6";
			}

		}
		else if (s == "violet") {
			if (i == 2 && result == "") {

			}
			else if (i == 2) {
				result += "0000000";
			}
			else {
				result += "7";
			}

		}
		else if (s == "grey") {
			if (i == 2 && result == "") {

			}
			else if (i == 2) {
				result += "00000000";
			}
			else {
				result += "8";
			}

		}
		else if (s == "white") {
			if (i == 2 && result == "") {

			}
			else if (i == 2) {
				result += "000000000";
			}
			else {
				result += "9";
			}

		}
	}
	if (result == ""){
		result = "0";
	}

	cout << result;
}