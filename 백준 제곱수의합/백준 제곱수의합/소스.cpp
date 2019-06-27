#include<iostream>
#include<cmath>
using namespace std;

int main() {
	int n;
	cin >> n;

	int *arr = new int[n+1];
	arr[0] = 0;
	arr[1] = 1;
	for (int i = 2; i <= n; i++) {
		int min;
		int sqr = sqrt(i) / 1;
		for (int k = sqr; k >= 1; k--) {
			int aaa;
			aaa = i - k*k;
			if (k == sqr) {
				min = arr[aaa]+1;
			
			
			}
			else{
				if (arr[aaa] < min) {
					min = arr[aaa] + 1;
				}

			}
			arr[i] = min;
		}
		
	}
	cout << arr[n];

}