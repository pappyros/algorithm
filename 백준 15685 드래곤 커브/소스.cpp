#include<iostream>
#include<vector>
using namespace std; int ty[4] = { 0,-1,0,1 }; int tx[4] = { 1,0,-1,0 }; bool arr[101][101];
class zoa {
public:
	int y, x;
};
class dragon {
public:
	int ind; int sede;
	vector<zoa>vrr;
};
int main() {
	int n; cin >> n; vector<dragon>drr;
	for (int i = 0; i < n; i++) {
		int a, b, c, d; cin >> a >> b >> c >> d;
		dragon dd; zoa i1; i1.y = b; i1.x = a; dd.sede = d; zoa i2; i2.y = b + ty[c]; i2.x = a + tx[c]; dd.ind = 1;
		dd.vrr.push_back(i1); dd.vrr.push_back(i2); drr.push_back(dd);
	}
	for (int i = 0; i < drr.size(); i++) {
		for (int k = 1; k <= drr[i].sede; k++) {
			int oy = drr[i].vrr[drr[i].ind].y; int ox = drr[i].vrr[drr[i].ind].x; drr[i].ind = drr[i].vrr.size();
			int num = drr[i].vrr.size();
			for (int p = 0; p < num ; p++) {
				int hay = drr[i].vrr[p].y - oy; int hax = drr[i].vrr[p].x-ox;
				zoa imz; imz.y = oy + hax; imz.x = ox - hay; drr[i].vrr.push_back(imz);
			}
		}
		for (int k = 0; k < drr[i].vrr.size(); k++) {
			arr[drr[i].vrr[k].y][drr[i].vrr[k].x] = true;
		}
	}int dap = 0;
	for (int i = 0; i < 100; i++) {
		for (int k = 0; k < 100; k++) {
						if (arr[i][k] == true && arr[i][k + 1] == true && arr[i + 1][k] == true && arr[i + 1][k + 1] == true)dap++;
		}
	}
	cout << dap;
}
