#include<iostream>
#include<vector>
#include<string>
using namespace std; vector<vector<int>>vrr;
int conv(char a) { return (int)(a - 97); }int dap = 0;
void func( bool alp[26], int n,int d, int ss) {
	if (n == d) {
		int imsi = 0;
		for (int i = 0; i < vrr.size(); i++) {
			for (int k = 0; k <= vrr[i].size(); k++) {
				if (k == vrr[i].size()) { imsi++;}
				else if (alp[vrr[i][k]] == 0)break;
			}
		}if (imsi > dap)dap = imsi;
	
	}
	else {
		for (int i = ss; i < 26; i++) {
			if (alp[i] == 1)continue;
			else {
				alp[i] = 1; func(alp, n + 1, d, i + 1); alp[i] = 0;
			}
		}
	}
}
int main() {
	int n, k; cin >> n >> k; bool alp[26];//anta tica
	fill(alp, alp + 26,0);
	alp[conv('a')] = true; alp[conv('n')] = true; alp[conv('c')] = true; alp[conv('t')] = true; alp[conv('i')] = true;
	if (k < 5)cout << 0;
	else {
		
		for (int i = 0; i < n; i++) {
			vector<int>vt;
			string tp; cin >> tp;
			bool tt[26]; fill(tt, tt + 26, 0);
			for (int k = 0; k < tp.size(); k++)tt[conv(tp[k])]=1;
			for (int k = 0; k < 26; k++)if (tt[k] == 1)vt.push_back(k);
			vrr.push_back(vt); 
		}
		func(alp, 0, k - 5, 0);
		cout << dap;
	}
	
	
}
