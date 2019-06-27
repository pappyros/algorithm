#include<iostream>
using namespace std;
int a = 0;
int b = 0;
int fibonacci(int n) {
	if (n == 0) {
		
		a++;
		return 0;
	}
	else if (n == 1) {
		
		b++;
		return 1;
	}
	else {
		return fibonacci(n-1) + fibonacci(n-2);
	}
}
int main(){
	int tc;
	int aaa;
	cin >> tc;
	aaa = tc;
	int *hoi = new int[tc];
	while(tc>0){
		int input;
		cin >> input;
		hoi[tc-1] = input;
		tc--;
	}
	for (int i = aaa; i >0;i--) {
		fibonacci(hoi[i - 1]);
		cout << a <<" "<< b << endl;
		a = 0;
		b = 0;
	}

}