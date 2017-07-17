#include<iostream>
#include<algorithm>
using namespace std;



int main() {
	int n, m;
	cin >> n >> m;
	int **left = new int*[m+1];
	int **right = new int*[m+1];


	for (int i = 0; i <= m; i++) {
		left[i] = new int[n];
		right[i] = new int[n];
	}




	int *arr = new int[n];

	for (int p = 0; p < n; p++) {
		cin >> arr[p];
	}



	//0ºÎ

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (arr[i] == 1) {
				left[0][i] = 1;
				right[0][i] = 0;
			}
			else {
				right[0][i] = 0;
				left[0][i] = 0;
			}

		}
		else {
			if (arr[i] == 1) {
				left[0][i] = left[0][i - 1] + 1;
				right[0][i] = right[0][i - 1];
			}
			else {
				left[0][i] = left[0][i - 1];
				right[0][i] = right[0][i - 1] + 1;
			}


		}
	}
	for (int i = 0; i < n; i++) {
		right[0][i]=0;
	}/*
	for (int i = 0; i < n; i++) {
		cout << left[0][i] << " ";
	}
	cout << endl;
	for (int i = 0; i < n; i++) {
		cout << right[0][i] << " ";
	}*/


	for (int i = 0; i < n; i++) {
		// Ã¹Â°
		if (i == 0) {
			if (arr[0] == 1) {
				for (int k = 0; k <= m; k++) {
					left[k][0] = 0;
					right[k][0] = 0;

				}
				left[0][0] = 1;
				//right[1][0] = 1;

			}
			else {
				for (int k = 0; k <= m; k++) {
					left[k][0] = 0;
					right[k][0] = 0;

				}
				right[1][0] = 1;
				//left[1][0] = 1;

			}


		}
		else {

			if (arr[i] == 1) {
				for (int k = 1; k <= m; k++) {
					left[k][i] = max(left[k][i - 1] + 1, right[k - 1][i - 1] + 1);
					right[k][i] = max(right[k][i - 1], left[k - 1][i - 1]);


				}


			}
			else {
				for (int k = 1; k <= m; k++) {
					right[k][i] = max(right[k][i - 1] + 1, left[k - 1][i - 1] + 1);
					left[k][i] = max(left[k][i - 1], right[k - 1][i - 1]);


				}

			}


		}

	}/*
	cout << "sv"<<endl;

	for (int i = 0; i <= m; i++) {
		for (int k = 0; k < n; k++) {
			cout << left[i][k] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i <= m; i++) {
		for (int k = 0; k < n; k++) {
			cout << right[i][k] << " ";
		}
		cout << endl;
	}*/

	int dap = 0;
	for (int i = 0; i <= m; i++) {
		if (left[i][n - 1] > dap) {
			dap = left[i][n - 1];
		}
	}
	for (int i = 0; i <= m; i++) {
		if (right[i][n - 1] > dap) {
			dap = right[i][n - 1];
		}
	}	cout << dap;
	
}