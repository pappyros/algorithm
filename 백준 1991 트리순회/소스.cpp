#include<iostream>
#include<string>
using namespace std;
string r1 = ""; string r2 = ""; string r3 = "";
class node {
public:
	char le = 0;
	char ri = 0;
}; node nrr[200];

void pre(char a) {
	if (a == 0)return;
	r1 += a;
	pre(nrr[a].le);
	pre(nrr[a].ri);
}
void in(char a) {
	if (a == 0)return;
	in(nrr[a].le);
	r2 += a;
	in(nrr[a].ri);
}
void pos(char a) {
	if (a == 0)return;
	pos(nrr[a].le);
	pos(nrr[a].ri);
	r3 += a;
}
int main() {
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		char a, b, c; cin >> a >> b >> c;
		nrr[a].le = (b == '.' ? 0 :b); nrr[a].ri = (c == '.' ? 0 :c);
	}

	pre('A');in('A');pos('A');
	cout <<r1<< endl; cout << r2 << endl; cout << r3;
}
