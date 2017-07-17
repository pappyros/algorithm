#include<iostream>
#include<string>
using namespace std;


int main() {
	string num;
	cin >> num;
	int arr[10] = { 0,0,0,0,0,0,0,0,0,0 };
	for (int i = 0; i < num.length(); i++) {
		int a = atoi(num.substr(i, 1).c_str());
		arr[a]++;
	}
	int k = (arr[6] + arr[9]);
	arr[6] = k / 2;
	arr[9] = k - arr[6];
	int max = -1;
	for (int i = 0; i < 10; i++) {
		if (arr[i] > max) {
			max = arr[i];
		}
	}
	cout << max;

}