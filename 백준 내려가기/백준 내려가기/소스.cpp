#include<iostream>
#include<algorithm>
using namespace std;
void first(int a, int **arr, int **mrr) {
	if (arr[0][0] > arr[0][1]) {
		arr[1][0] = a + arr[0][0];
	}
	else {
		arr[1][0] = a + arr[0][1];
	}
	if (mrr[0][0] < mrr[0][1]) {
		mrr[1][0] = a + mrr[0][0];
	}
	else {
		mrr[1][0] = a + mrr[0][1];
	}
}
void second(int a, int **arr, int **mrr) {
	int imsi[3];
	imsi[0] = arr[0][0];
	imsi[1] = arr[0][1];
	imsi[2] = arr[0][2];
	sort(imsi, imsi + 3);
	arr[1][1] = a + imsi[2];

	imsi[0] = mrr[0][0];
	imsi[1] = mrr[0][1];
	imsi[2] = mrr[0][2];
	sort(imsi, imsi + 3);
	mrr[1][1] = a + imsi[0];

}
void third(int a, int **arr, int **mrr) {
	if (arr[0][1] > arr[0][2]) {
		arr[1][2] = a + arr[0][1];
	}
	else {
		arr[1][2] = a + arr[0][2];
	}

	if (mrr[0][1] < mrr[0][2]) {
		mrr[1][2] = a + mrr[0][1];
	}
	else {
		mrr[1][2] = a + mrr[0][2];
	}

}
int main() {
	int row;
	cin >> row;
	int **arr = new int*[2];
	arr[0] = new int[3];
	arr[1] = new int[3];
	int **mrr = new int*[2];
	mrr[0] = new int[3];
	mrr[1] = new int[3];
	for (int i = 0; i < row; i++) {
		if (i == 0) {
			cin >> arr[0][0] >> arr[0][1] >> arr[0][2];
			mrr[0][0] = arr[0][0];
			mrr[0][1] = arr[0][1];
			mrr[0][2] = arr[0][2];
			continue;
		}
		int a, b, c;
		cin >> a >> b >> c;
		first(a, arr,mrr);
		second(b, arr,mrr);
		third(c, arr,mrr);
		arr[0][0] = arr[1][0];
		arr[0][1] = arr[1][1];
		arr[0][2] = arr[1][2];
		mrr[0][0] = mrr[1][0];
		mrr[0][1] = mrr[1][1];
		mrr[0][2] = mrr[1][2];
	}
	sort(arr[0], arr[0] + 3);
	sort(mrr[0], mrr[0] + 3);
	cout << arr[0][2] << " " << mrr[0][0];
}