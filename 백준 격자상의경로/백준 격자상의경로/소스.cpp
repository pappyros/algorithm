#include<iostream>
using namespace std;

int main() {
	int N, M,kkk;
	cin >> N >> M >> kkk;
	int **arr = new int*[N];
	int number = 1;
	if (kkk !=0) {
		int Y, X;
		for (int i = 0; i < N; i++) {
			arr[i] = new int[M];


			for (int k = 0; k < M; k++) {
				arr[i][k] = number;
				if (number == kkk) {
					Y = i;
					X = k;
				}
				number++;
			}
		}
		int togob;
		for (int i = 0; i <= Y; i++) {

			for (int k = 0; k <= X; k++) {
				if (i == 0) {
					arr[i][k] = 1;
					continue;

				}
				if (k == 0) {
					arr[i][k] = 1;
					continue;
				}
				arr[i][k] = arr[i][k - 1] + arr[i - 1][k];
			}
		}
		togob = arr[Y][X];
		////////////////
		for (int i = Y; i < N; i++) {

			for (int k = X; k < M; k++) {
				if (i == Y) {
					arr[i][k] = 1;
					continue;

				}
				if (k == X) {
					arr[i][k] = 1;
					continue;
				}
				arr[i][k] = arr[i][k - 1] + arr[i - 1][k];
			}
		}

		cout << togob*arr[N - 1][M - 1];
	}
	else {//k==0

		for (int i = 0; i < N; i++) {
			arr[i] = new int[M];


			for (int k = 0; k < M; k++) {
				arr[i][k] = number;
				
				number++;
			}
		}

		for (int i = 0; i < N; i++) {

			for (int k = 0; k < M; k++) {
				if (i == 0) {
					arr[i][k] = 1;
					continue;

				}
				if (k == 0) {
					arr[i][k] = 1;
					continue;
				}
				arr[i][k] = arr[i][k - 1] + arr[i - 1][k];
			}
		}

		cout << arr[N - 1][M - 1];

	}
	
}