#include<iostream>
#include<cmath>
#pragma warning (disable:4996)
using namespace std;
long int number = 0;
int zero = 0;
void func(long int h,int a,int b,int q,int w) {
	if (h == 2&&zero==0) {
		if (a == q&&b == w) {
			zero = 1;
			cout<< number<<endl;

		}
		else {
			number++;
		}
		if (a == q&&b+1 == w) {
			zero = 1;
			cout<< number << endl;
		}
		else {
			number++;
		}
		if (a+1 == q&&b == w) {
			zero = 1;
			cout<< number << endl;
		}
		else {
			number++;
		}
		if (a+1 == q&&b+1 == w) {
			zero = 1;
			cout<< number << endl;
		}
		else {
			number++;
		}
		
		

	}
	else if(zero==0) {
		func(h / 2, a, b,q,w);
		func(h / 2, a, b + h / 2,q,w);
		func(h / 2, a + h / 2, b,q,w);
		func(h / 2, a + h / 2, b +h/2,q,w);
	}
}

int main() {

	
	int n;
	int a, b;
	while (cin>>n>>a>>b) {
		long int hei = (long int)pow(2, n);



		func(hei, 0, 0, a, b);
		number = 0;
		zero = 0;
	}
	

}