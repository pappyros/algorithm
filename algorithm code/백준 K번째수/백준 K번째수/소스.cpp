#include<iostream>
#include<vector>
#include<algorithm>
#pragma warning(disable:4996)
using namespace std;


long long func(long long n, long long k, long long start, long long end) {//k¹øÂ°
	long long mid = (start + end) / 2;
	long long sum = 0;
	long long civa = n;
	for (long long i = 1; i <= n; i++) {
		if (i*n <= mid) {
			sum += n;
			continue;
		}
		if (i > mid)break;
		
		for (long long p = civa; p >= 1; p--) {
			if (p*i <= mid) {
				civa = p;
				sum += civa;
				break;
			}
		}	
	
	}
	if (start > end) {
		return start;
	}
	else {
		if (sum >= k) {
			return func(n, k, start, mid - 1);
		}
		else if (sum < k) {
			return func(n, k, mid + 1, end);
		}


	}

}

int main() {

	

	long long n, k;
	cin >> n >> k;

	
	cout << func(n, k, 1, n*n);


}

