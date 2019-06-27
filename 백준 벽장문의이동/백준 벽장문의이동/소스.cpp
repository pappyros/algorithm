#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;

class moment {
public:
	int open1, open2, sum;

};

int main() {
	int moon, open1,open2,query;
	cin >> moon >> open1 >> open2 >> query;

	int *arr = new int[query];
	for (int i = 0; i < query; i++) {
		int a;
		cin >> a;
		arr[i] = a;
	}
	moment **mrr = new moment*[2];
	mrr[0] = new moment[query];
	mrr[1] = new moment[query];

	for (int i = 0; i < query; i++) {
		if (i == 0) {
			int case1 = abs(open1 - arr[i]);
			int case2 = abs(open2 - arr[i]);
			if (case1 > case2) {//open2°¡ ´õ°¡±õ
				mrr[0][i].open2 = arr[i];
				mrr[0][i].open1 = open1;
				mrr[0][i].sum = case2;
				mrr[1][i].open2 = open2;
				mrr[1][i].open1 = arr[i];
				mrr[1][i].sum = case1;
			}
			else {
				mrr[0][i].open1 = arr[i];
				mrr[0][i].open2 = open1;
				mrr[0][i].sum = case1;
				mrr[1][i].open1 = open2;
				mrr[1][i].open2 = arr[i];
				mrr[1][i].sum = case2;

			}

		}
		else {
			int case1 = abs(mrr[0][i-1].open1 - arr[i]);
			int case2 = abs(mrr[0][i-1].open2 - arr[i]);
			int case3 = abs(mrr[1][i - 1].open1 - arr[i]);
			int case4 = abs(mrr[1][i - 1].open2 - arr[i]);
			int temp1, temp2;
			if (case1 > case2) {
				temp1 = case2;

			}
			else {
				temp1 = case1;
			}
			if (case3 > case4) {
				temp2 = case4;

			}
			else {
				temp2 = case3;
			}
			if (temp1 + mrr[0][i - 1].sum > temp2 + mrr[1][i - 1].sum) {
				
			}
			else {

			}




		}
		
		
		
	}

	cout << sum;

}