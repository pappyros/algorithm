#include<iostream>
using namespace std;
int main() {

	int a, b, c;
	int modul;
	cin >> a >> b;
	modul = (a / b);
	a = a - modul*b;
	cout << modul << ".";
	for (int i = 0; i < 20; i++) {
		a *= 10;
		modul = (a / b);
		a = a - modul*b;
		cout << modul;


	}
}