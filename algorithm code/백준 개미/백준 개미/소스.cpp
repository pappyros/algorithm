#include<iostream>
using namespace std;

int main() {


	int w, h, sw, sh, sec;
	cin >> w >> h>>sw>>sh>>sec;
	sw += sec;
	sh += sec;
	sw = sw % (2 * w);
	sh = sh % (2 * h);
	if (sw > w) {
		sw = 2 * w - sw;

	}
	if (sh > h) {
		sh = 2 * h - sh;
	}
	cout << sw << " " << sh;

	
}