#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {

	int n;
	cin >> n;
	int sum = 0;
	int zari;
	int imsi = 0;

	if (n < 10) {
		cout << n;
	}
	else {
		for (int i = 1; 1; i++) {
			int k = pow(10, (i - 1));
			sum += i * 9 * k;


			if (n < sum) {
				zari = i;
				n = n - (sum - i * 9 * k);
				break;
			}

		}

		int p = n / zari;
		int z = n%zari;

		if (z == 0) {

			int dap = pow(10, (zari - 1)) + p;
			
			string str = to_string(dap-1);
			cout << str.substr(zari-1, 1);

		}
		else {


			int dap = pow(10, (zari - 1)) + p;




			string str = to_string(dap);
			cout << str.substr(z - 1, 1);

		}

	}
	

	
}
