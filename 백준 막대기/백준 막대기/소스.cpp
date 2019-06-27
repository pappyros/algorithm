#include<iostream>
using namespace std;


int bin(int N) {
	int binary[25] = { 0 };
	int number = N;
	int onesnum = 0;
	
	for (int i = 0; i<25; i++)
	{
		binary[i] = number % 2;
		number = number / 2;
	}
	for (int i = 0; i<25; i++)
	{
		if (binary[i] == 1) {
			onesnum++;
		}
		
	}
	return onesnum;

}
int main() {
	int a;
	cin >> a;

	cout << bin(a);

}