#include<iostream>
#include<algorithm>
using namespace std;


int main() {
	int num;
	cin >> num;
	int *arr = new int[num+4];
	for (int i = 0; i < num+4; i++){


		
		if (i >= num) {
			arr[i] = -100;
		}
		else {
			cin >> arr[i];

		}


	}
	sort(arr, arr + num);
	int *result = new int[num];
	for (int i = 0; i < num; i++) {
		
			int soo = 4;
			for (int k = 1; k <= 4; k++) {
				if (arr[i + k] <= arr[i] + 4&&arr[i+k]>=arr[i]) {
					soo--;
				}
				else {
					break;
				}
				

			}
			result[i] = soo;
		




	}

	sort(result, result + num);
	cout << result[0];

}