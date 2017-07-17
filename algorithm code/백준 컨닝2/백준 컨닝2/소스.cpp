#include<iostream>
using namespace std;
int main() {

	int tc;

	
	cin >> tc;
	int *result = new int[tc];

	for (int k = 0; k<tc; k++) {

		int a, b;
		cin >> a >> b;
		char**arr = new char*[a];
		for (int i = 0; i < a; i++) {
			arr[i] = new char[b];
			cin >> arr[i];



		}
		

		
		int count1 = 0;
		int count2 = 0;
		for (int i = 0; i < a; i++) {
			for (int p = 0; p < b; p = p + 2) {
				if (arr[i][p] == '.') {
					count1++;
				}
			}
		}

		for (int i = 0; i < a; i++) {
			for (int p = 1; p < b; p = p + 2) {
				if (arr[i][p] == '.') {
					count2++;
				}
			}
		}

		if (count1 > count2) {
			result[k] = count1;
		}
		else {
			result[k] = count2;
		}

		


	}
	for (int i = 0; i < tc; i++) {
		cout << result[i] << endl;
	}

}