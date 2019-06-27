#include<iostream>
#include<vector>
#include<string>
#include<cmath>
using namespace std;
long int num[10] = { 0,0,0,0,0,0,0,0,0,0 };
void func(int nu) {
	for (int i = 0; i < 10; i++) {
		num[i]+= nu;
	}
}
int main() {

	string book;
	
	cin >> book;
	
	
	for (int i = book.length() - 1; i >= 0; i--) {
		for (int k = 0; k < i; k++) {
			num[atoi((book.substr(k,1)).c_str())]+=atoi(book.substr(i,book.length()-i).c_str());
		}
		func(atoi((book.substr(0,i )).c_str())*pow(10,book.length()-i-1));


	}
	for (int i = 0; i < book.length(); i++) {
		++num[atoi((book.substr(i, 1)).c_str())];
	}
	for (int i = 0; i < 10; i++) {
		cout << num[i] << " ";
	}

	
}