#include<iostream>
using namespace std;
int com(int a[],int n) {
	int sum = 0;
	
		if (a[n-1] == 0) {
			a[n] == 1;
			return com(a, n + 1);
		}
		else if (a[n] == 9) {
			a[n] == 8;
			return com(a, n + 1);

		}
		else {
			


		}

	
}


int main() {
	int tc;
	cin >> tc;
	int *arr = new int[tc];




}