#include<iostream>
#include<string>
using namespace std;
int main() {
	int jung;
	cin >> jung;
	int num = 1;
	while (true) {
		int a, b,c,d,e;
		a = jung / 10;
		b = jung - a * 10;
		c = a + b;
		d = c / 10;
		e = c - d * 10;
		if (b * 10 + e == jung) {
			cout << num;
			break;
		}
		else {
			num++;
				jung = b * 10 + e;
				
		}

	}
	
}