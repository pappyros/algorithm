
#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;


int main() {

	int subin, dong;
	cin >> subin >> dong;

	int *arr = new int[100002];
	for (int i = 0; i < 100002; i++) {
		arr[i] = 100000000;
	}
	for (int i = 1; i <= subin;i++) {
		arr[i] = subin - i;

	}
	/////////////////////////////////////////////////////
		for (int i = subin * 2; i < 100002; i = i * 2) {
			
				arr[i] = 0;
			
			for (int k = i + 1; k < 100002; k++) {

				arr[k] = k - i;

			}

			for (int k = i - 1; k > 0; k--) {
				int imsi = i - k;
				if (imsi > arr[k]) {
					break;

				}
				else {
					arr[k] = imsi;
				}

			}
		}
	
	for (int i = subin +1; i < 100002; i++) {
		if (i % 2 == 1) {
			int minus = arr[i + 1] + 1;
			int plus = arr[i - 1] + 1;
			int current = arr[i];
			int siva[3] = { minus,plus,current };
			sort(siva, siva + 3);
			arr[i] = siva[0];

		}
		else {
			int minus = arr[i + 1]+1;
			int plus = arr[i - 1]+1;
			int multi = arr[i / 2];
			int current = arr[i];
			int siva[4] = { minus,plus,multi,current};
			sort(siva, siva + 4);
			arr[i] = siva[0];
			
		}
	}

	cout << arr[dong];
}



