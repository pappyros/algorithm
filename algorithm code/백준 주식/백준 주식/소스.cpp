#include<iostream>
using namespace std;

int main() {
	int tc;

	cin >> tc;
	long long int * result = new long long int[tc];
	for (int i = 0; i < tc; i++) {
		int day;
		int stock = 0;
		long long int ben = 0;
		cin >> day;
		int * value = new int[day];
		int * max = new int[day];
		for (int k = 0; k < day; k++) {
			cin >> value[k];
		}
		for (int k = day-1; k >=0; k--) {
			if (k == day - 1) {
				max[k] = value[k];
				continue;
			}
			
			if (value[k] > max[k + 1]) {
				max[k] = value[k];
			}
			else {
				max[k] = max[k + 1];
			}

		}

		for (int k = 0; k < day; k++) {
			if (value[k] == max[k]&&stock==0) {//암것도 안하거나
				continue;

			}
			if (value[k] < max[k]) {//주식을 사거나
				ben -= value[k];
				stock++;
				continue;
			}
			if (value[k] == max[k]) {//팔거나
				ben += max[k] * stock;
				stock = 0;
				continue;
			}
			
		}

		result[i] = ben;


		





	}
	for (int i = 0; i < tc; i++) {
		cout << result[i] << endl;
	}
}



