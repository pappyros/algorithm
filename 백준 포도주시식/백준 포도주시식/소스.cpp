#include<iostream>
#include<cmath>
#include<algorithm>
using namespace std;
int main() {
	int num;
	cin >> num;
	int *arr = new int[num];
	int *zer = new int[num];
	int *one = new int[num];
	int *two = new int[num];
	for (int i = 0; i < num; i++) {
		cin >> arr[i];
	}
	zer[0] = 0;
	zer[1] = arr[0];
	one[0] = arr[0];
	two[0] = 0;
	one[1] = arr[1];
	two[1] = one[0] + arr[1];
	for (int i = 2; i < num; i++) {
		zer[i] = max(zer[i - 1], max(one[i - 1], two[i - 1]));
		one[i] = zer[i - 1] + arr[i];
		two[i] = one[i - 1] + arr[i];
	}

	cout << max(zer[num - 1], max(one[num - 1], two[num - 1]));



}