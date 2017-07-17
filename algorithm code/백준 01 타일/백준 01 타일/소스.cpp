#include<iostream>
#include<cmath>
using namespace std;
int combination(int a, int b) {

	long long int c = 1;
	for (int i = 0; i < b; i++) {
		c = (c*(a - i) / (b - i))%15746;

		
		}
		

		return c;
	

}
int main() {
	
	int n;
	cin >> n;
	int *arr = new int[n];
	arr[0] = 1;
	arr[1] = 2;

	for (int i = 2; i < n; i++) {
		arr[i] = (arr[i - 1] + arr[i - 2]) % 15746;
	}
	cout << arr[n - 1];


}