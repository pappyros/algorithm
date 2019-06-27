#include<iostream>
#include<algorithm>
#include <iomanip>
using namespace std;

int main() {
	int tc;
	cin >> tc;
	float * arr = new float[tc];
	for (int i = 0; i < tc; i++) {
		cin >> arr[i];
	}
	sort(arr, arr + tc);
	float sum = 0;
	for (int i = 0; i < tc; i++) {
		sum += arr[i] / arr[tc - 1];
	}
	float value=(sum / tc)*100;
	int value2= (sum / tc) * 100;

	cout << fixed;
	cout.precision(2);
	cout << value;
	
}