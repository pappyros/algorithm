#include<iostream>
#pragma warning (disable:4996)
using namespace std;


int main() {

	int N, m, M, T, R;
	scanf("%d %d %d %d %d", &N, &m, &M, &T, &R);
	
	int min = 0;
	int now = m;
	int total = m + N*T;
	min += N;

	if (total >= M) {

		int over = total - M;
		if (R > M - m) {
			if (over%R == 0) {
				min += (over / (M-m));
			}
			else {
				min += (over / (M-m)) + 1;
			}
			
		}
		else {
			if (over%R == 0) {
				min += (over / R);
			}
			else {
				min += (over / R) + 1;
			}

		}
	}
	


	if (T > M - m) {
		printf("-1");
	}
	else {
		printf("%d", min);
	}
	
}