#include<iostream>
#include<vector>
using namespace std;
int gap;
int r=0;
void func(int index, vector<int>arr, int noo) {
	if (arr.size() == index)return;
	int value = arr[index]+noo;
	if (value == gap) {
		r++;
		func(index + 1, arr, noo + arr[index]);
		func(index + 1, arr, noo);
	}
	else{

		func(index + 1, arr, noo+arr[index]);
		func(index + 1, arr, noo);

	    

}



}


		



int main() {
	/*
	int n;
	cin >> n >> gap;
	int* arr = new int[n];
	int* dp = new int[n]; 

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			cin >> dp[i];
			continue;
		}
		int t;
		cin >> t;
		dp[i] = dp[i - 1] + t;
	}
	int result = 0;

	for (int i = 0; i < n; i++) {
		if (i == 0) {
			for (int k = 0; k < n; k++) {
				if (dp[k] == gap) {
					result++;
				}
			}

		}
		else {
			for (int k = i; k < n; k++) {
				if (dp[k] - dp[i - 1] == gap) {
					result++;
				}
			}

		}

	}

	cout << result;
	*/

	int n;
	cin >> n >> gap;
	vector<int>arr;
	for (int i = 0; i < n; i++) {
		int f;
		cin >> f;
		arr.push_back(f);
	}

	func(0, arr, 0);
	cout << r;
}