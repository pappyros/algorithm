#include<iostream>
#include<string>
#include<vector>
using namespace std;

int main() {
	try {
		vector<string>vec;
		string str;
		cin >> str;
		vec.push_back("9");
		if (str.substr(0, 1) == "0") {
			cout << 0;
		}
		else {
			for (int i = 0; i < str.size(); i++) {
				if (str.substr(i, 1) == "0")throw 0;
				if (str.substr(i + 1, 1) == "0") {
					vec.push_back(str.substr(i, 2));
					
					if (str.substr(i, 1) > "2") throw 0;
					i++;
				}
				else {
					vec.push_back(str.substr(i, 1));

				}
			}
			int *nrr = new int[vec.size()];
			nrr[0] = 1;

			for (int i = 1; i < vec.size(); i++) {
				if (atoi((vec[i]).c_str()) >= 10) {
					nrr[i] = nrr[i - 1]%1000000;//두자리이상.
				}
				else if (atoi((vec[i - 1] + vec[i]).c_str()) > 26) {
					nrr[i] = nrr[i - 1]%1000000;

				}
				else {
					nrr[i] = nrr[i - 2]%1000000;
					nrr[i] += nrr[i - 1]%1000000;
					nrr[i] = nrr[i] % 1000000;
				}
			}


			cout << nrr[vec.size() - 1];




		}
	}
	catch (int a) {
		cout << a;
		

	}

}