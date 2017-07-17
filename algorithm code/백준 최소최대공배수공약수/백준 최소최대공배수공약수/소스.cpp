#include<iostream>
#include<stdio.h>
#pragma warning(disable : 4996)
using namespace std;

int main() {

	int a, b;
	cin >> a >> b;
	if (a > b) {
		int c = a;
		a = b;
		b = c;

	}
	int yak = 1;
	int bae = 1;
	for (int i = 2; i <= a; i++) {
		if (a%i == 0 && b%i == 0) {
			a = a / i;
			b = b / i;
			yak *= i;
			i--;
		}
		else if (a == i) {
			break;
		}
	}
	bae = yak*a*b;
	cout << yak << endl;
	cout << bae << endl;

}