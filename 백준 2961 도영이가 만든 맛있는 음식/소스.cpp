#include<iostream>
#include<vector>
#include<cmath>
using namespace std;
class rec {
public : 
	int s, d;
};
int main(){
	int n; cin >> n;
	vector<rec> rrr; for (int i = 0; i < n; i++) {
		int a, b; cin >> a >> b; rec tp; tp.s = a; tp.d = b; rrr.push_back(tp);
	}int m = pow(2, n); int cha = 1000000001;
	for (int i = 1; i <= m - 1; i++) {
		 int sin = 1;int ssn = 0;
		for (int k = 0; k < n; k++) {
			if (i&(1 << (k))) {
				sin *= rrr[k].s; ssn += rrr[k].d;
			}
		}
		cha = (cha > (abs(sin - ssn)) ? abs(sin - ssn) : cha);
	}
	cout << cha;
}
