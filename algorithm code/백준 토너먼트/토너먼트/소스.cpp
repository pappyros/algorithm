#include<iostream>
using namespace std;
int result = 1;

void func(int a[],int n,int num) {
	if (n == 1) {
		return;
	}
	if (n % 2 == 0) {
		int * arr = new int[n / 2];
		int k = 0;
		for (int i = 0; i < n; i=i+2) {
			if (a[i] == 1 && a[i + 1] == 1) {
				cout<< num;
			}
			else if (a[i] == 1) {
				arr[k] = a[i];
				k++;
				
			}
			else {
				arr[k] = a[i+1];
				k++;
				
			}
			

		}
		num++;
		func(arr, n / 2, num);


	}


	else {
		int * arr = new int[n / 2 + 1];
		int k = 0;
		for (int i = 0; i < n; i = i + 2) {
			if (i == n - 1) {
				arr[k] = a[i];
			}

			if (a[i] == 1 && a[i + 1] == 1) {
				cout<< num;
			}
			else if (a[i] == 1) {
				arr[k] = a[i];
				k++;
				
			}
			else {
				arr[k] = a[i+1];
				k++;
				
			}

		}
		
		num++;
		func(arr, (n / 2)+1, num);



	}
}

int main() {
	int tc, a, b;
	cin >> tc >> a >> b;
	int *tor = new int[tc];
	
	for (int i = 0; i < tc; i++) {
		tor[i] = 0;
	}
	tor[a-1] = 1;
	tor[b-1] = 1;
	


	func(tor, tc, 1);





}