#include<iostream>
#include<algorithm>
#include<vector>
#include<cmath>
#pragma warning(disable:4996)

using namespace std;
bool sumzero(int**dp, int k, int max) {
	int sum = 0;
	for (int i = 0; i < max+1; i++) {
		sum += dp[i][k];
	}
	if (sum == 0) {
		return true;
	}
	else {
		return false;
	}
}
int main() {

	int song, start, max;
	scanf("%d%d%d", &song, &start, &max);
	int *arr = new int[song];
	int **dp = new int*[max+1];
	for (int i = 0; i < song; i++) {
		scanf("%d", &arr[i]);
		
		
	}
	for (int i = 0; i < max+1; i++) {
		dp[i] = new int[song];
		for (int k = 0; k < song; k++) {
			dp[i][k] = 0;
		}
	}
	

	for (int i = 0; i < song; i++) {
		if (i == 0) {
			if (start - arr[i] >= 0) {
				dp[start - arr[i]][i] = 1;
				
			}
			if (start + arr[i] <= max) {
				dp[start + arr[i]][i] = 1;
			}
			if (sumzero(dp, i,max)) {
				break;
			}


		}
		else {//첫째가아니면
			for (int k = 0; k < max+1; k++) {
				if (dp[k][i - 1] == 1) {
					if (k + arr[i] <= max) {
						dp[k + arr[i]][i] = 1;
					}
					if (k - arr[i] >= 0) {
						dp[k - arr[i]][i] = 1;
					}
				}
			}
			if (sumzero(dp, i,max)) {
				break;
			}
		}
	}

	int ma = -1;
	for (int i = max; i >= 0; i--) {
		if (dp[i][song - 1] == 1) {
			ma = i;
			break;
		}
	}
	

	cout << ma;

}