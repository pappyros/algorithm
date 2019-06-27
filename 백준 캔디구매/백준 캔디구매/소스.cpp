#include<iostream>
#include<cmath>

using namespace std;

int main() {
	int candy;
	cin >> candy;
	int gong;
	cin >> gong;
	gong = pow(10,gong);
	if ((candy - (candy / gong)*gong) >= gong / 2) {
		cout << (candy / gong)*gong + gong;
	}
	else {
		cout << (candy / gong)*gong;
	}

}