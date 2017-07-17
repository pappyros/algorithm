#include<iostream>
#include<string>
#include<vector>
#include <string.h>
using namespace std;

bool func(const char *arr) {
	int alp[100];
	for (int i = 0; i < 100; i++) {
		alp[i] = 0;
	}
	int kk = strlen(arr);

	for (int i = 0; i <= kk; i++) {
		if (i == kk) {
			return true;
		}
		alp[(int)arr[i]]++;
		if (alp[(int)arr[i]] % 3 != 0) {
			
			continue;
		}
		else {
			if (arr[i] == arr[i + 1]) {
				i++;
				continue;

			}
			else {
				return false;
			}
		}
	}

}

int main() {

	int tc;
	cin >> tc;

	bool *result = new bool[tc];
	
	for (int i = 0; i < tc; i++) {

		string A;
		vector<char> moon;
		cin >> A;
		const char * arr = new char[A.length()];
		arr = A.c_str();

		result[i] = func(arr);
		
		




	}
	for (int i = 0; i < tc; i++) {
		if (result[i] == 1) {
			cout << "OK" << endl;
		}
		else if(result[i]==0){
			cout << "FAKE" << endl;
		}
	}
}