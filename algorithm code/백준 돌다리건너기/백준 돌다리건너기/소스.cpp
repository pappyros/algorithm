#include<iostream>
#include<string>

using namespace std;

int main() {

	string doo, evil, angel;
	cin >> doo >> evil >> angel;
	int arr[20][2][100];
	for (int i = 0; i < 20; i++) {
		for (int k = 0; k < 2; k++) {
			for (int p = 0; p < 100; p++) {
				arr[i][k][p] = 0;
			}
		}
	}
	for (int i = 0; i < doo.size(); i++) {
		if (i == 0) {
			for (int k = 0; k < evil.size(); k++) {
				if (evil.substr(k, 1) == doo.substr(0, 1)) {
					arr[0][0][k] = 1;
				}
			}
			for (int p = 0; p < angel.size(); p++) {
				if (angel.substr(p, 1) == doo.substr(0, 1)) {
					arr[0][1][p] = 1;
				}
			}

		}
		else {
			for (int k = 0; k < evil.size(); k++) {
				if (evil.substr(k, 1) == doo.substr(i, 1)) {
					for (int p = 0; p < k; p++) {
						arr[i][0][k] += arr[i - 1][1][p];

					}
				}

			}
			for (int k = 0; k < angel.size(); k++) {
				if (angel.substr(k, 1) == doo.substr(i, 1)) {
					for (int p = 0; p < k; p++) {
						arr[i][1][k] += arr[i - 1][0][p];
					}
				}

			}


		}
	}
	int sum = 0;
	for (int i = 0; i < evil.size(); i++) {
		sum += arr[doo.size() - 1][0][i];
		sum += arr[doo.size() - 1][1][i];
	}
	cout << sum;

}