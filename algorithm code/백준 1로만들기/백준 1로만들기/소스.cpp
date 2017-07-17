#include<iostream>
#include<algorithm>
using namespace std;

int main() {
	int n;
	cin >> n;
	int *arr = new int[2000001];
	for (int i = 0; i <= 2000000; i++) {
		arr[i] = 0;
	}
	arr[0] = 99999999;
	arr[1] = 0;
	arr[2] = 1;
	arr[3] = 1;
	arr[4] = 2;
	arr[5] = 3;
	arr[6] = 2;

	for (int i = 7; i <= n+10; i++) {
		int two = (i % 2 == 0);
		int three = (i % 3 == 0);
		if (two&&three) {
			arr[i] = min(min(arr[i/3],arr[i/2]), arr[i - 1])+1;

		}
		else if(two||three) {
			if (two == 1) {
				arr[i] = min(arr[i / 2], arr[i - 1])+1;

			}
			else {
				arr[i] = min(arr[i / 3], arr[i - 1])+1;

			}

		}
		else {
			arr[i] = arr[i - 1]+1;

		}

	}

	cout << arr[n];

}