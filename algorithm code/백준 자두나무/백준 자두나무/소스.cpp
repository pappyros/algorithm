#include<iostream>
#include<algorithm>
using namespace std;



int main() {
	int n, m;
	cin >> n >> m;
	int **left = new int*[m];
	int **right = new int*[m];
	for (int i = 0; i < n; i++) {
		left[i] = new int[n];
		right[i] = new int[n];
	}



	
	int *arr = new int[n];
	
	for (int p = 0; p < n; p++) {
		cin >> arr[p];
	}
	



	for (int i = 0; i < n; i++) {
		if (i == 0) {
			if (arr[i] == 1) {
				left[0][i] = 1;
			}
			else {
				right[0][i] = 1;
			}
			
		}
		else {
			if (arr[i] == 1) {
				left[0][i] = left[0][i-1]+1;
				right[0][i] = right[0][i - 1];
			}
			else {
				left[0][i] = left[0][i - 1] ;
				right[0][i] = right[0][i - 1]+1;
			}


		}
	}


	for (int i = 0; i < n; i++) {
		// ù°
		if (i == 0) {
			if (arr[0] == 1) {
				for (int k = 0; k < m; k++) {
					left[k][0] = 0;
					right[k][0] = 0;

				}
				left[0][0] = 1;

			}
			else {
				for (int k = 0; k < m; k++) {
					left[k][0] = 0;
					right[k][0] = 0;

				}
				right[1][0] = 1;

			}


		}
		else {

			if (arr[i] == 1) {
				for (int k = 0; k < m; k++) {
					left[k][i] = max(left[k][i-1]+1,right[k-1][i-1]+1);
					right[k][i] = max(right[k][i - 1], left[k - 1][i - 1]);
					

				}


			}
			else {
				for (int k = 0; k < m; k++) {
					right[k][i] = max(right[k][i - 1] + 1, left[k - 1][i - 1] + 1);
					left[k][i] = max(left[k][i - 1], right[k - 1][i - 1]);


				}

			}


		}

	}

	for (int i = 0; i < m; i++) {
		cout << left[n - 1][i] << " " << right[n - 1][i] << endl;
	}
}