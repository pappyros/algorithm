#include<iostream>
#include<string>
#include<cmath>

using namespace std;

int main() {
	string a, b;
	cin >> a >> b;
	int c = a.length() - b.length();
	if (c >= 0) {
		for (int i = 0; i < c; i++) {
			b = "0" + b;
		}

	}
	else {
		c = abs(c);
		for (int i = 0; i < c; i++) {
			a = "0" + a;
		}
	}


	int k = 0;
	int swit = 0;
	for (int i = 0; i < a.length(); i++) {
		if (a.substr(i, 1) ==b.substr(i, 1)) {
			
			swit = 1;
			if (a.substr(i, 1) == "8") {
				k++;
			}
		}
		else {
		
				break;
			
		}

	}

	cout << k;
	


}