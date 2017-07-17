#include<iostream>
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

	int X, Y, soo;
	cin >> X >> Y >> soo;
	bat **arr = new bat*[Y];
	for (int k = 0; k < Y; k++) {
		arr[k] = new bat[X];
	}
	for (int p = 0; p < soo; p++) {
		int x, y;
		cin >> x >> y;
		arr[y - 1][x - 1].bachu = 1;
	}
	int warm = 1;
	for (int y = 0; y < Y; y++) {
		for (int x = 0; x < X; x++) {
			if (arr[y][x].bachu == 1 && arr[y][x].inzub == 0) {
				check(arr, y, x, warm, Y, X);
				warm++;
			}

		}





		//result[i] = warm - 1;




	}
	int*dab = new int[warm];
	for (int aa = 1; aa <= warm - 1; aa++) {
		int pppp = 0;
		for (int y = 0; y < Y; y++) {
			for (int x = 0; x < X; x++) {
				if (arr[y][x].inzub == aa) {
					pppp++;
				}



			}

		}
		dab[aa] = pppp;
	}

	int fff = 0;
	for (int z = 1; z <= warm - 1; z++) {
		if (dab[z] > fff) {
			fff = dab[z];
		}
	}
	cout << fff;
}
	
