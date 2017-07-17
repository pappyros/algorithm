#include<iostream>
#include<string>
#include<cstdio>
using namespace std;
int main() {
	int tc;
	int bun = 0;
	cin >> tc;
	string *arr = new string[tc];
	for (int i = 0; i < tc; i++) {

		int a, b, result;

		cin >> a >> b;
		string getst = to_string(a);

		string mandui = getst.substr(getst.length() - 1, 1);
		if (mandui == "1") {
			arr[bun++] = "1";

		}
		else if (mandui == "2") {
			int nan = b % 4;
			if (nan == 1) {
				arr[bun++] = "2";
			}
			else if (nan == 2) {
				arr[bun++] = "4";
			}
			else if (nan == 3) {
				arr[bun++] = "8";
			}
			else if (nan == 0) {
				arr[bun++] = "6";
			}


		}
		else if (mandui == "3") {
			int nan = b % 4;
			if (nan == 1) {
				arr[bun++] = "3";
			}
			else if (nan == 2) {
				arr[bun++] = "9";
			}
			else if (nan == 3) {
				arr[bun++] = "7";
			}
			else if (nan == 0) {
				arr[bun++] = "1";
			}

		}
		else if (mandui == "4") {
			int nan = b % 2;
			if (nan == 1) {
				arr[bun++] = "4";
			}
			else if (nan == 0) {
				arr[bun++] = "6";
			}
		

		}
		else if (mandui == "5") {
			arr[bun++] = "5";

		}
		else if (mandui == "6") {
			arr[bun++] = "6";

		}
		else if (mandui == "7") {
			int nan = b % 4;
			if (nan == 1) {
				arr[bun++] = "7";
			}
			else if (nan == 2) {
				arr[bun++] = "9";
			}
			else if (nan == 3) {
				arr[bun++] = "3";
			}
			else if (nan == 0) {
				arr[bun++] = "1";
			}

		}
		else if (mandui == "8")
		{
			int nan = b % 4;
			if (nan == 1) {
				arr[bun++] = "8";
			}
			else if (nan == 2) {
				arr[bun++] = "4";
			}
			else if (nan == 3) {
				arr[bun++] = "2";
			}
			else if (nan == 0) {
				arr[bun++] = "6";
			}

		}
		else if (mandui == "9") {
			int nan = b % 2;
			if (nan == 1) {
				arr[bun++] = "9";
			}
			else if (nan == 0) {
				arr[bun++] = "1";
			}
			

		}
		else if (mandui == "0") {
			arr[bun++] = "10";

		}
			/*
		int k = b;
		result = a;
		string re = "";
		string kkk = to_string(a);
		re += kkk.substr(kkk.length() - 1, 1);
		while (k > 0) {

			result *= a;
			string ppp = to_string(result);
			ppp = ppp.substr(ppp.length() - 1, 1);
			if (ppp == kkk) {
				break;
			}
			else {
				re += ppp;
			}
			k--;

		}

		int ddd = b % re.length();
		if (ddd == 0) {
			arr[bun++] = re.substr(re.length() - 1, 1);
		}
		else {
			arr[bun++] = re.substr(ddd - 1, 1);
		}*/

	}
		
		
	
	for (int i = 0; i < bun; i++) {
		cout << arr[i] << endl;
	}
}