#include<iostream>
#include<cmath>
#include<string>
#include<vector>
using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int chai = a.length()- b.length();
	chai = abs(chai);
	
	if (a.length() > b.length()) {
		for (int i = 0; i < chai; i++) {
			b = "0" + b;
		}
	}
	else {
		for (int i = 0; i < chai; i++) {
			a = "0" + a;
		}

	}
	vector<int> result;

	
	
	int plus = 0;
	for (int i = a.length() - 1; i >= -1; i--) {
		if (i != -1) {
			int p = atoi(a.substr(i, 1).c_str()) + atoi(b.substr(i, 1).c_str()) + plus;
			if (p == 1) {
				result.push_back(1);
				plus = 0;

			}
			else if (p == 2) {
				result.push_back(0);
				plus = 1;

			}
			else if (p == 3) {
				result.push_back(1);
				plus = 1;


			}
			else if (p == 0) {
				result.push_back(0);
				plus = 0;

			}
		}
		else {
			int p = plus;
			if (p == 1) {
				result.push_back(1);
				plus = 0;

			}
			else if (p == 2) {
				result.push_back(0);
				i--;
				plus = 1;

			}
			else if (p == 3) {
				result.push_back(1);
				i--;
				plus = 1;


			}
			else if (p == 0) {
				result.push_back(0);
				plus = 0;

			}

		}
		

	}
	if (result[result.size() - 1] == 0) {
		result.pop_back();
	}

	int swit = 0;



	for (int i = result.size()-1; i >= 0; i--) {
		if (i==0) {
			cout << result[i];

		}
		else if (swit == 0 && result[i] == 0) { 
			continue;
		}
		else {
			swit = 1;
			cout << result[i];
		}
	}
	

}