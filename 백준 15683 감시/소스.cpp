#include<iostream>
#include<stdio.h>
#include<vector>
#include<algorithm>
#include<string>
#include<iomanip>
#include<cmath>
#include<iomanip>
using namespace std;
vector<vector<int>>arr; int n, m;  int mi = 999; int ccc = 0;
class cmr {
public:
	int type; int y, x;
}; vector<cmr>crr;
int count(vector<vector<int>>brr) {
	int cnt = 0;
	for (int i = 1; i <= n; i++)for (int k = 1; k <= m; k++)if (brr[i][k] == 0)cnt++; return cnt;
}
vector<vector<int>> valid(int y, int x, int ty, vector<vector<int>>brr) {
	if (ty == 1) {
		for (int i = y-1; i >= 1; i--) {
			if (brr[i][x] == 6)break;
			else if (brr[i][x] == 0)brr[i][x] = 7;
		}
	}
	else if (ty == 2) {
		for (int i = x+ 1; i <=m; i++) {
			if (brr[y][i] == 6)break;
			else if (brr[y][i] == 0)brr[y][i] = 7;
		}
	}
	else if (ty == 3) {
		for (int i = y + 1; i <= n; i++) {
			if (brr[i][x] == 6)break;
			else if (brr[i][x] == 0)brr[i][x] = 7;
		}
	}
	else {
		for (int i = x - 1; i >=1; i--) {
			if (brr[y][i] == 6)break;
			else if (brr[y][i] == 0)brr[y][i] = 7;
		}
	}
	return brr;
}
void func(int st, int ed, vector<vector<int>> brr) {
	if (st == ed) {
		int tp = count(brr); if (tp < mi)mi = tp; 
		return;
	}
	int ty = crr[st].type; int yy = crr[st].y; int xx = crr[st].x;
	vector<vector<int>> kkk;
	if (ty == 1) {
		kkk=valid(yy, xx, 1,brr); func(st + 1, ed,kkk);
		kkk=valid(yy, xx, 2,brr); func(st + 1, ed,kkk); 
		kkk=valid(yy, xx, 3,brr); func(st + 1, ed,kkk); 
		kkk=valid(yy, xx, 4,brr); func(st + 1, ed,kkk); 
	}
	else if (ty == 2) {
		kkk=valid(yy, xx, 1,brr); kkk=valid(yy, xx, 3,kkk); func(st + 1, ed,kkk); 
		kkk=valid(yy, xx, 2,brr); kkk=valid(yy, xx, 4,kkk); func(st + 1, ed,kkk); 
	}
	else if (ty == 3) {
		kkk=valid(yy, xx, 1,brr); kkk=valid(yy, xx, 2,kkk); func(st + 1, ed,kkk); 
		kkk = valid(yy, xx, 3, brr); kkk = valid(yy, xx, 2, kkk); func(st + 1, ed, kkk);
		kkk = valid(yy, xx, 3, brr); kkk = valid(yy, xx, 4, kkk); func(st + 1, ed, kkk);
		kkk = valid(yy, xx, 1, brr); kkk = valid(yy, xx, 4, kkk); func(st + 1, ed, kkk);
	}
	else if (ty == 4) {
		kkk=valid(yy, xx, 1,brr); kkk=valid(yy, xx, 2,kkk); kkk=valid(yy, xx, 3,kkk); func(st + 1, ed,kkk); 
		kkk = valid(yy, xx, 4, brr); kkk = valid(yy, xx, 2, kkk); kkk = valid(yy, xx, 3, kkk); func(st + 1, ed, kkk);
		kkk = valid(yy, xx, 1, brr); kkk = valid(yy, xx, 4, kkk); kkk = valid(yy, xx, 3, kkk); func(st + 1, ed, kkk);
		kkk = valid(yy, xx, 1, brr); kkk = valid(yy, xx, 2, kkk); kkk = valid(yy, xx, 4, kkk); func(st + 1, ed, kkk);
		
	}
	else {
		kkk=valid(yy, xx, 1,brr); kkk=valid(yy, xx, 2,kkk); kkk=valid(yy, xx, 3,kkk); kkk=valid(yy, xx, 4,kkk); func(st + 1, ed,kkk); 
	}

}

int main() {
	 cin >> n >> m;
	 arr.assign(n+1, vector<int>(m+1, 0));
 
	for (int i = 1; i <= n; i++) {
		for (int k = 1; k <= m; k++) {
			int tp; cin >> tp;
			if (tp != 0 && tp != 6) {
				cmr cm; cm.y = i; cm.x = k; cm.type = tp; arr[i][k] = tp; crr.push_back(cm);
			}
			else {
				arr[i][k] = tp;
			}
		}
	}
	func(0, crr.size(),arr); cout << mi;
	
}
