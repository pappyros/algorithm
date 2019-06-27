#include<iostream>
#pragma warning(disable:4996)
using namespace std;


int main() {
	int a, b;
	scanf("%d%d", &a, &b);
	int **arr = new int*[a];

	for (int i = 0; i < a; i++) {
		arr[i] = new int[b+1];
		for (int k = 0; k <= b; k++) {
			if (k == 0) {
				arr[i][k] = 0;
				//scanf("%d", &arr[i][k]);
				//cin >> arr[i][k];
			}
			else {
				int siva;
				scanf("%d", &siva);
				//cin >> siva;
				arr[i][k] = siva + arr[i][k - 1];
			}
		}

	}

	int que;
	//cin >> que;
	scanf("%d", &que);
	int*result = new int[que];
	for (int i = 0; i < que; i++) {
		int fy, fx,ty,tx;
		scanf("%d%d%d%d", &fy, &fx,&ty,&tx);
		int sum = 0;
		
		for (int k = fy - 1; k <= ty-1; k++) {
			sum += arr[k][tx] - arr[k][fx - 1];
		}
		result[i] = sum;
	}
	


	for (int i = 0; i < que; i++) {
		cout << result[i] << "\n";
	}


}