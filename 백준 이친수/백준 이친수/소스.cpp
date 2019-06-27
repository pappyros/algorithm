#include<iostream>
using namespace std;
/*
int func(int n, int start,int arr[]) {
	if (start  == n) {
		return 1;
	}

	if (start == 0) {
		arr[start] = 1;
		return func(n, start + 1, arr);

	}
	else if (start == 1) {
		arr[start] = 0;
		return func(n, start + 1, arr);
	}
	else {
		if (arr[start - 1] == 1) {
			arr[start] = 0;
			return func(n, start + 1, arr);
		}
		else {
			arr[start] = 1;
			int A = func(n, start + 1, arr);
			arr[start] = 0;
			int B = func(n, start + 1, arr);
			return A + B;

		}
	}
}

int fibo(int n) {
	if (n == 1) {
		return 1;
	}
	else if (n == 2) {
		return 1;
	}


		return fibo(n - 1) + fibo(n - 2);
}*/
int fibon(int k)
{
	int i, cur, prev1, prev2;
	cur = 1; prev1 = 1; prev2 = 1;
	for (i = 3; i <= k; i++)
	{
		cur = prev1 + prev2;
		prev2 = prev1; prev1 = cur;
	}
	return cur;
}
#include <iostream>
using namespace std;
long long fibo[100] = { 0,1 };
int main() {
	int n;
	cin >> n;
	for (int i = 2; i <= n; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	cout << fibo[n] << '\n';
	return 0;
}