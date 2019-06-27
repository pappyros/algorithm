#include<iostream>
#include<math.h>

using namespace std;




int main() {
	double absol, w, h,x,imsi;
	cin >> absol >> w >> h;
	x = sqrt(pow(absol, 2.0)) / sqrt((pow(w, 2.0) + pow(h, 2.0)));
	
	double res1 = x*w;
	double res2 = x*h;
	cout <<  res1 << " " << res2<<endl;
	



}