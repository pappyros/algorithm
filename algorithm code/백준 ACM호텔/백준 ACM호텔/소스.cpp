#include<iostream>


using namespace std;

int main() {
	int test;
	cin >> test;
	int *result = new int[test];
	for (int i = 0; i < test; i++) {
		int h, w, k;
		cin >> h >> w >> k;
		int ho, ch;
		if (k % h==0) {
			ho = k / h;
			ch = h;

		}
		else {
			ho = k / h + 1;
			ch = k%h;

		};
		
		result[i] = ch * 100 + ho;


	}
	for (int i = 0; i < test; i++) {
		cout << result[i] << endl;

	}

}