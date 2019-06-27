#include<iostream>
#include<vector>
#include<string>
using namespace std;

int main() {
	string st; cin >> st; vector<int>irr; vector<char>crr;
	string imsi = ""; int sz = st.size();
	for (int i = 0; i < st.size(); i++) {
		if (st[i] == '+' || st[i] == '-') {
			irr.push_back(atoi(imsi.c_str())); crr.push_back(st[i]); imsi = "";
		}
		else imsi += st[i];
	}irr.push_back(atoi(imsi.c_str()));
	for (int i = 0; i < crr.size(); i++) {
		if (crr[i] == '+') {
			irr[i] += irr[i + 1]; irr.erase(irr.begin() + i + 1); crr.erase(crr.begin() + i); i--;
		}
	}int tot = irr[0];
	for (int i = 1; i < irr.size(); i++)tot -= irr[i]; cout << tot;
}
