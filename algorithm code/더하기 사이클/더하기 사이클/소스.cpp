#include<iostream>
using namespace std;

int main() {
	int a;
	cin >> a;
	int origin = a;
	int cycle = 0;
	while (true) {
		int first, last, sum;
		first = a / 10;
		last = a - first * 10;
		sum = first + last;
		cycle++;
		
		a = last * 10 + sum % 10;
		if (origin == a) {
			cout << cycle;
			break;
		}
	}
}