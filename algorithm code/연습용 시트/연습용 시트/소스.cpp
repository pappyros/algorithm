#include<iostream>
using namespace std;
int main() {
	int a, b;
	cin >> a>>b;
	int **arr = new int*[a];
	

	for (int i = 0; i < a;i++) {
		arr[i] = new int[b];
		for (int k = 0; k < b; k++) {
			
			arr[i][k]=0;
			cout << arr[i][k];
		}
		cout << endl;
		
	}

}