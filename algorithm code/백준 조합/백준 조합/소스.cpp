#include<iostream>
using namespace std;


unsigned long long int combination(long long int b, long long int a) {


	unsigned long long int c = 1;

	for (int i = 1; i <= a; i++) {
		c = (c*b / i);
		b--;
	}
	return c;

}
int main() {

	long long int a, b;
	cin >> a >> b;
	cout << combination(a, b);


}