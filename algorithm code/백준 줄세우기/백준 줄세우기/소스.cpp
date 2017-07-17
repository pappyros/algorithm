#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include <iomanip>
using namespace std;


int main() {

	int num;
	cin >> num;
	double *arr = new double[num];
	double *mrr = new double[num];
	double imsi = 0;
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}

	for (int i = num - 1; i >= 0; i--) {
		int max = 1;
		for (int k = i + 1; k < num; k++) {
			if (arr[k] > arr[i]) {
				if (max <= mrr[k]) {
					max = mrr[k] + 1;
				}
			}




		}
		mrr[i] = max;
	}

	sort(mrr, mrr + num);
	/*for (int i = 0; i < num; i++) {
	cout << mrr[i] << " ";
	}*/
	cout << num-mrr[num - 1];

}