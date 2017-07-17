#include<iostream>
#include<algorithm>
using namespace std;

void Merge(int *a, int start,int mid,  int end) {
	sort(a + start, a + end+1);

	/*
	int *imsi = new int[end - start+1];
	int as = start;
	int ae = mid;
	int bs = mid + 1;
	int be = end;
	for (int i = 0; i < end - start + 1; i++) {
		if ((a[as] > a[bs])&&(bs<=be)) {
			imsi[i] = a[bs];
			bs++;
		}
		else {
			imsi[i] = a[as];
			as++;

		}

	}
	for (int i = 0; i < end - start + 1; i++) {
		a[start + i] = imsi[i];

	}
	
	*/

}

void func(int *a,int start,int end) {
	if (start >= end) {
		
	}
	else {
		func(a, start, (start + end) / 2);
		func(a, 1 + ((start + end) / 2),end);
		Merge(a, start, (start + end) / 2, end);

	}

}


int main() {


	int num;
	cin >> num;
	int *arr = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	func(arr, 0, num - 1);
	for (int i = 0; i < num; i++) {
		cout << arr[i] << endl;
	}
	



}