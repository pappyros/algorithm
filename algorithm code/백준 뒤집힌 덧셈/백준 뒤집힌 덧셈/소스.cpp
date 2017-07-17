#include<iostream>
#include<string>
#include<cmath>
using namespace std;

int main() {
	string A;
	string B;
	cin >> A ;
	cin >> B ;
	double C = 0;
	double D = 0;

	for (int i = 0; i < A.length(); i++) {
		
		C+=atoi(A.substr(i,1).c_str()) * pow(10, i);

	}
	for (int i = 0; i < B.length(); i++) {

		D += atoi(B.substr(i, 1).c_str()) * pow(10, i);

	}
	int E = C + D;
	string K = to_string(E);
	int Result = 0;
	for (int i = 0; i < K.length(); i++) {

		Result += atoi(K.substr(i, 1).c_str()) * pow(10, i);

	}
	cout << Result;
	


}