#include<iostream>
#include<string>
using namespace std;

void func(char **arr, int a, int b) {
	int n;
	if (a > b) {
		n = b;
	}
	else {
		n = a;
	}
	for (int i = n; i >= 1; i--) {
		
	}



}


int main() {
	int a, b;
	cin >> a >> b;
	int **arr = new int*[a];
	for (int i = 0; i < a; i++) {
		string str;
		cin >> str;
		arr[i] = new int[b];
		for (int k = 0; k < b; k++) {
			arr[i][k] = atoi(str.substr(k, 1).c_str());
		}
		
	}
	for (int i = 0; i < a; i++) {
		for (int k = 1; k < b; k++) {
			if (arr[i][k] != 0) {
				arr[i][k] = arr[i][k] + arr[i][k - 1];
			}
		}
	}
	for (int i = 1; i < a; i++) {
		for (int k = 0; k < b; k++) {
			if (arr[i][k] != 0) {
				arr[i][k] = arr[i][k] + arr[i-1][k];
			}
		}
	}
	for (int i = 0; i < a; i++) {
		for (int k = 0; k < b; k++) {
			cout << arr[i][k];
		}
		cout<<endl;
	}
	
	
	//cout<<func(arr, a, b);

	
}