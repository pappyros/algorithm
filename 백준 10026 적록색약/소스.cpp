#include<iostream>
using namespace std;
char arr[101][101]; int one = 0; int n; int ty[4] = { 1,-1,0,0 }; int tx[4] = { 0,0,1,-1 };
bool visit[101][101]; int two = 0;
void dfs(int y, int x,char k) {
	visit[y][x] = true;
	for (int i = 0; i < 4; i++) {
		if (y + ty[i] >= 1 && y + ty[i] <= n&&x + tx[i] >= 1 && x + tx[i] <= n&&visit[y + ty[i]][x + tx[i]] == false&& arr[y + ty[i]][x + tx[i]]==k) {
			dfs(y + ty[i], x + tx[i], k);
		}
	}
}

int main() {
cin >> n;
	for (int i = 1; i <= n; i++)for (int k = 1; k <= n; k++)cin >> arr[i][k];
	for (int i = 1; i <= n; i++)for (int k = 1; k <= n; k++) {
		if (visit[i][k] == false) { dfs(i, k,arr[i][k]); one++; }
	}
	for (int i = 1; i <= n; i++)for (int k = 1; k <= n; k++) {
		visit[i][k] = false;
		if (arr[i][k] == 'G')arr[i][k] = 'R';
	}
	for (int i = 1; i <= n; i++)for (int k = 1; k <= n; k++) {
		if (visit[i][k] == false) { dfs(i, k, arr[i][k]); two++; }
	}
	cout << one<<" "<<two;

}
