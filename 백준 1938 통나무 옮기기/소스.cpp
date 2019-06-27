#include<iostream>
#include<string>
#include<deque>
#include<vector>
using namespace std;
int vrr[2][51][51];
char arr[51][51];
bool tp = 0;
int ty[4] = { 1,-1,0,0 }; int tx[4] = { 0,0,1,-1 };
class state {
public:
	bool tp;
	int y, x;
};
vector<state>st; vector<state>ed;
int sy, sx, ey, ex; bool ss, es;
int main() {
	int n; cin >> n;
	for (int i = 1; i <= n; i++) {
		string tp; cin >> tp;
		for (int k = 1; k <= n; k++) {
			vrr[0][i][k] = -1; vrr[1][i][k] = -1;
			char cc = tp[k - 1];
			if ('B' == cc) {
				state tp; tp.y = i; tp.x = k; st.push_back(tp);
			}
			else if ('E' == cc) {
				state tp; tp.y = i; tp.x = k; ed.push_back(tp);
			}
			arr[i][k] = cc;
		}
	}//
	if (st[0].x == st[1].x) {
		ss = 1; sx = (st[0].x + st[1].x + st[2].x) / 3; sy = (st[0].y + st[1].y + st[2].y) / 3;
	}
	else {
		ss = 0; sx = (st[0].x + st[1].x + st[2].x) / 3; sy = (st[0].y + st[1].y + st[2].y) / 3;
	}
	if (ed[0].x == ed[1].x) {
		es = 1; ex = (ed[0].x + ed[1].x + ed[2].x) / 3; ey = (ed[0].y + ed[1].y + ed[2].y) / 3;
	}
	else {
		es = 0; ex = (ed[0].x + ed[1].x + ed[2].x) / 3; ey = (ed[0].y + ed[1].y + ed[2].y) / 3;
	}
	state fir; fir.y = sy; fir.x = sx; fir.tp = ss; vrr[ss][sy][sx] = 0;
	deque<state>qu; qu.push_back(fir);
	int dap = 0;
	while (!qu.empty()) {
		
		bool temps = qu.front().tp; int tempy = qu.front().y; int tempx = qu.front().x;
		if (es == temps&&tempy == ey&&tempx == ex) {
			dap=vrr[temps][tempy][tempx];
			break;
		}
		if (temps == 0) {
			for (int i = 0; i < 4; i++) {
				if (arr[tempy + ty[i]][tempx + tx[i]] != '1'&&arr[tempy + ty[i]][tempx + tx[i] - 1] != '1'&&arr[tempy + ty[i]][tempx + tx[i] + 1] != '1'&&vrr[0][tempy + ty[i]][tempx + tx[i]] == -1) {
					if (tempy +ty[i]>0&&tempy+ty[i]<=n&&tempx+tx[i]>1&&tempx+tx[i]<=n-1) {
						vrr[0][tempy + ty[i]][tempx + tx[i]] = vrr[0][tempy][tempx] + 1;
						state imsi; imsi.tp = 0; imsi.y = tempy + ty[i]; imsi.x = tempx + tx[i]; qu.push_back(imsi);
					}
				}
			}
			if (vrr[1][tempy][tempx] == -1 && arr[tempy+1][tempx] != '1'&&arr[tempy-1][tempx] != '1'&&tempy+1<=n&&tempy-1>0) {
				if (arr[tempy-1][tempx-1] != '1'&&arr[tempy-1][tempx+1] != '1'&&arr[tempy+1][tempx-1] != '1'&&arr[tempy+1][tempx+1] != '1') {
					vrr[1][tempy][tempx] = vrr[0][tempy][tempx] + 1;
					state imsi; imsi.tp = 1; imsi.y = tempy; imsi.x = tempx; qu.push_back(imsi);
				}
			}
		}
		else {
			for (int i = 0; i < 4; i++) {
				if (arr[tempy + ty[i]][tempx + tx[i]] != '1'&&arr[tempy + ty[i]+1][tempx + tx[i]] != '1'&&arr[tempy + ty[i]-1][tempx + tx[i]] != '1'&&vrr[1][tempy + ty[i]][tempx + tx[i]] == -1) {
					if (tempy + ty[i] > 1 && tempy + ty[i] <= n-1&&tempx + tx[i] > 0 && tempx + tx[i] <= n) {
						vrr[1][tempy + ty[i]][tempx + tx[i]] = vrr[1][tempy][tempx] + 1;
						state imsi; imsi.tp = 1; imsi.y = tempy + ty[i]; imsi.x = tempx + tx[i]; qu.push_back(imsi);
					}
				}
			}
			if (vrr[0][tempy][tempx] == -1 && arr[tempy][tempx+1] != '1'&&arr[tempy][tempx-1] != '1'&&tempx+1<=n&&tempx-1>0) {
				if (arr[tempy - 1][tempx - 1] != '1'&&arr[tempy - 1][tempx + 1] != '1'&&arr[tempy + 1][tempx - 1] != '1'&&arr[tempy + 1][tempx + 1] != '1') {
					vrr[0][tempy][tempx] = vrr[1][tempy][tempx] + 1;
					state imsi; imsi.tp = 0; imsi.y = tempy; imsi.x = tempx; qu.push_back(imsi);
				}
			}

		}
		qu.pop_front();
	}
	cout << dap;

}
