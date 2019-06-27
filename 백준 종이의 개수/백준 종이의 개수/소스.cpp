#include<iostream>

using namespace std;
int res[3] = { 0,0,0 };
void func(int **arr, int y, int x, int cur) {
	int temp=arr[y][x];
	bool ok = true;
	for (int i = y; i < y + cur; i++) {
		for (int k = x; k < x + cur; k++) {
			if (temp != arr[i][k]) {//다를경우
				for (int p = y; p < y+cur; p = p + (cur / 3)) {
					for (int q = x; q < x+cur; q = q + (cur / 3)) {
						func(arr, p, q, cur / 3);
						//cout << p<<" "<<q << endl;
					}
				}

				//ok = false;
				return ;
			}
			

				
		}
	}
	res[temp + 1]++;



	
}

int main() {

	int n;
	cin >> n;
	int**arr = new int *[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new int[n];
		for (int k = 0; k < n; k++) {
			cin >> arr[i][k];
		}
	}
	

	func(arr, 0, 0, n);
	cout << res[0] << endl << res[1] << endl << res[2] << endl;
}