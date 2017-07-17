#include<iostream>
#include<string>
#include<algorithm>
using namespace std;


class bat {
public:
	int bachu = 0;
	int inzub = 0;


};

void check(bat **a, int y, int x, int k, int maxy, int maxx) {
	if (a[y][x].bachu == 1 && a[y][x].inzub == 0) {
		a[y][x].inzub = k;
		if (x != maxx - 1) {
			check(a, y, x + 1, k, maxy, maxx);
		}
		if (y != maxy - 1) {
			check(a, y + 1, x, k, maxy, maxx);
		}
		if (y != 0) {
			check(a, y - 1, x, k, maxy, maxx);
		}
		if (x != 0) {
			check(a, y, x - 1, k, maxy, maxx);
		}
	}
}


int main() {
	
	int X;
		cin >> X ;
		bat **arr = new bat*[X];
		for (int k = 0; k < X; k++) {
			arr[k] = new bat[X];
			string input;
			cin >> input;
			for (int i = 0; i < X; i++) {
				arr[k][i].bachu = atoi(input.substr(i, 1).c_str());
			}
		}
		//ÀÔ·Â³¡
		int warm = 1;
		for (int y = 0; y < X; y++) {
			for (int x = 0; x < X; x++) {
				if (arr[y][x].bachu == 1 && arr[y][x].inzub == 0) {
					check(arr, y, x, warm, X, X);
					warm++;
				}

			}

		}
		int danzi = 0;
		for (int k = 0; k < X; k++) {
			
			for (int i = 0; i < X; i++) {
				if (arr[k][i].inzub >= danzi) {
					danzi = arr[k][i].inzub;
				}
			}
			
		}
		int *mrr = new int[danzi];
		for (int k = 0; k < danzi; k++) {
			mrr[k] = 0;
		}
		for (int k = 0; k < X; k++) {

			for (int i = 0; i < X; i++) {
				if (arr[k][i].inzub!=0) {
					mrr[(arr[k][i].inzub) - 1]++;
					
				}
			}

		}
		sort(mrr, mrr + danzi);
		cout << danzi << endl;
		for (int k = 0; k < danzi; k++) {
			cout << mrr[k] << endl;
		}
		





}