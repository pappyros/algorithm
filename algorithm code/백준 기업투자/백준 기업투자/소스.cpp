#include<iostream>

using namespace std;

int main() {

	int money, corp;
	cin >> money >> corp;
	int**arr = new int*[money + 1];
	for (int i = 0; i <= money; i++) {
		arr[i] = new int[corp + 1];
	}
	for (int i = 1; i <= money; i++) {
		int mon;
		cin >> mon;
		for (int k = 1; k <= corp; k++) {
			cin >> arr[mon][k];
		}
	}
	for (int i = 1; i <= corp; i++) {
		arr[0][i] = 0;
	}
	int *tooza = new int[corp + 1];
	for (int i = 0; i <= corp; i++) {
		tooza[i] = 0;
	}


	int current = 0;
	for (int i = 1; i <= money; i++) {
		int upper;
		int max = current;
		for (int k = 1; k <= corp; k++) {
			if (max < current + arr[tooza[k+1]][k]- arr[tooza[k]][k]) {
				upper = k;
				max = current + arr[tooza[k + 1]][k] - arr[tooza[k]][k];
			}

		}
		tooza[upper]++;
		for (int k = 1; k <= corp; k++) {
			if (max < arr[i][k]) {
				max = arr[i][k];
				for (int p = 1; p <= corp; p++) {
					tooza[p] = 0;
				}
				tooza[k] = i;
			}
		}
		current = max;
	}

	cout << current;

}
/*
4 2
1 5 1
2 6 5
3 7 9
4 10 15*/