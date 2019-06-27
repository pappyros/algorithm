#include<iostream>
#include<vector>
#include<deque>
#include<string>
using namespace std; bool er[10]; bool vrr[1000001];
class st {
public:
	int num, co;
};
int main() {
	fill(vrr, vrr + 1000001, false);
	int n, m; cin >> n >> m;
	if (n != 102) {
		for (int i = 0; i < m; i++) {
			int tp; cin >> tp; er[tp] = true;
		}deque<st>qu; st asi; asi.co = 0; asi.num = 100; qu.push_back(asi); vrr[100] = true;
		st asi1; asi1.co = 1; asi1.num = 99; qu.push_back(asi1); vrr[99] = true;
		st asi2; asi2.co = 1; asi2.num = 101; qu.push_back(asi2); vrr[101] = true;
		for (int i = 0; i < 1000001; i++) {
			if (i == 99 || i == 100 || i == 101 || i == 102)continue;
			string temp = to_string(i); bool oh = true;
			for (int k = 0; k < temp.size(); k++) {
				int haha = atoi(temp.substr(k, 1).c_str());
				if (er[haha] == true) {
					oh = false; break;
				}
			}
			if (oh) {
				st temps; temps.num = i; temps.co = temp.size(); vrr[i] = true; qu.push_back(temps);
			}
		}

		while (!qu.empty()) {
			int fn, fz; fn = qu.front().num; fz = qu.front().co;
			if (n == fn) {
				cout << fz; break;
			}
			if (vrr[fn + 1] == false && fn + 1 <= 500000) {
				vrr[fn + 1] = true;
				st temps; temps.num = fn + 1; temps.co = fz + 1; qu.push_back(temps);
			}
			if (vrr[fn - 1] == false && fn - 1 >= 0) {
				vrr[fn - 1] = true;
				st temps; temps.num = fn - 1; temps.co = fz + 1; qu.push_back(temps);
			}
			qu.pop_front();
		}
	}
	else cout << 2;
}
