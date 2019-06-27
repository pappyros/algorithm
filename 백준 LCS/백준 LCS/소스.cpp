#include<iostream>
#include<string>
using namespace std;

int main() {

	string A, B;
	cin >> A >> B;
	int sum = 0;
	for (int i = 0; i < A.size(); i++) {
		int imsi = 0;
		for (int k = i; k < A.size(); k++) {
			
			for (int p = 0; p < B.size(); p++) {
				if (A.substr(k, 1) == B.substr(p, 1)) {
					imsi++;
					k++;
				}
			}
			if (imsi > sum)sum = imsi;
		}
		
		
	}

	cout << sum;
	
}