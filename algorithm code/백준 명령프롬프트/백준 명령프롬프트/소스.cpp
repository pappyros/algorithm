#include<iostream>
#include<string>
using namespace std;




int main() {
	int tc;
	cin >> tc;
	char **a = new char*[tc];

	for (int i = 0; i < tc; i++) {
		a[i] = new char[50];
		cin >> a[i];
		

		
		
	}
	char *result = new char[50];
	
	for (int i = 0; i < 50; i++) {
		result[i] = a[0][i];
		for (int k = 1; k < tc; k++) {
			if (a[k - 1][i] != a[k][i]) {
				result[i] = '?';
				break;
			}
			result[i] = a[k][i];

		}
	
	}


	cout << result;



	
}