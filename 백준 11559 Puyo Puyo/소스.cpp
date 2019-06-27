#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;
char arr[13][7]; int ty[4] = { 1,-1,0,0 }; int tx[4] = { 0,0,1,-1 }; int combo = 0; bool visit[13][7]; int noo = 0;
void jung() {
	for (int i = 1; i <= 6; i++) {
		for (int k = 12; k >= 1; k--) {
			if (arr[k][i] == '.') {
				for (int p = k - 1; p >= 1; p--) {
					if (arr[p][i] != '.') {
						swap(arr[k][i], arr[p][i]); break;
					}
				}
			}
		}
	}
}
void vzero() {
	for (int i = 1; i <= 12; i++) {
		for (int k = 1; k <= 6; k++)visit[i][k] = false;
	}
}
void cdfs(int y, int x, char k) {
	visit[y][x] = true; noo++;
	for (int i = 0; i < 4; i++) {
		if (y + ty[i] >= 1 && y + ty[i] <= 12 && x + tx[i] >= 1 && x + tx[i] <= 6 && visit[y + ty[i]][x + tx[i]] == false && arr[y + ty[i]][x + tx[i]] == k) {
			cdfs(y + ty[i], x + tx[i], k);
		}
	}
}
void bdfs(int y, int x, char k) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		if (y + ty[i] >= 1 && y + ty[i] <= 12 && x + tx[i] >= 1 && x + tx[i] <= 6 && visit[y + ty[i]][x + tx[i]] == false && arr[y + ty[i]][x + tx[i]] == k) {
			bdfs(y + ty[i], x + tx[i], k);
		}
	}
	arr[y][x] = '.';
}
int main() {
	for (int i = 1; i <= 12; i++) {
		for (int k = 1; k <= 6; k++)cin >> arr[i][k];
	}bool what;
	do {
		what = false;
		for (int i = 1; i <= 12; i++) {
			for (int k = 1; k <= 6; k++) {
				if (arr[i][k] != '.') {
					cdfs(i, k, arr[i][k]); vzero();
					if (noo >= 4) {

						bdfs(i, k, arr[i][k]); vzero(); what = true;
					}
					noo = 0;
				}
			}
		}if (what == true)combo++;
		jung();
	} while (what);
	cout << combo;

}
