#include<iostream>
using namespace std;


int bin(int N,int K,int m) {
	int binary[25] = { 0 };
	int number = N;
	int onesnum = 0;
	int mool = m;
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
	if (onesnum <= K) {
		return mool;
	}
	else {
		bin(N + 1, K, mool + 1);
	}

}

int main() {
	int N, K, num;
	cin >> N >> K;
	cout<<bin(N, K, 0);
}