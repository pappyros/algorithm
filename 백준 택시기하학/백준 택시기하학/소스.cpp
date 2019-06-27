#include<iostream>
#include<iomanip>
#define _USE_MATH_DEFINES

#include<math.h>
//#define _USE_MATH_DEFINES

using namespace std;

int main(){
	

	double n;
	cin >> n;

	cout << fixed;
	double one = n*n*M_PI;
	double two = 2 * n*n;
	cout.precision(6);
	cout.setf(ios::showpoint);
	cout << one<<endl;

	cout << two;


}