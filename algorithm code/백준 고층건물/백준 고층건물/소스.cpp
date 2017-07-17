#include<iostream>
#include<cmath>
#include<algorithm>
#pragma warning(disable:4996);
using namespace std;

int main() {
	int num;
	scanf("%d", &num);
	double*arr = new  double[num+1];
	int *result = new int[num + 1];
	
	for (int i = 1; i <= num; i++) {
		cin >> arr[i];
	}

	for (int i = 1; i <= num; i++) {
		double maxx = -1000000001;
		int left = 0;
		int right = 0;
		for (int k = i + 1; k <= num;k++) {
			double kiul = (arr[k]-arr[i]) / (k - i);
			if (kiul > maxx) {
				maxx = kiul;
				right++;
			}

		}
		maxx = 1000000001;
		for (int k = i - 1; k >= 1; k--) {
			double kiul = (arr[k] - arr[i]) / (k - i);
			if (kiul < maxx) {
				maxx = kiul;
				left++;
			}

		}
		result[i] = left+right;

	}

	int kkk = 0;
	for (int i = 1; i <= num; i++) {
		if (result[i]>kkk) {
			kkk = result[i];

		}
	}
	cout << kkk;



}