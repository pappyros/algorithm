#include<iostream>
using namespace std;
/*
int combination(long long int b, long long int a) {


		long long int c = 1;
		
		for (int i = 1; i <= a; i++) {
			c = (c*b / i)%1000000000;
			b--;
		}
		return c;
		
}
int main() {

	int N, K;
	
	
	cin >> N >> K;
	long long int result = 0;
	if (N >= K) {
		for (int i = 0; i <= K - 1; i++) {
			result += (combination(K, i)*combination(N - 1, K - i - 1)) % 1000000000;
			result = result % 1000000000;
		}
	}
	else {
		for (int i = K-N; i <= K - 1; i++) {
			result += (combination(K, i)*combination(N - 1, K - i - 1)) % 1000000000;
			result = result % 1000000000;
		}
	}

	cout << result << endl;


	

}*/


int main() {

	int soo, n;
	cin >> soo >> n;
	long long int **arr = new long long int*[n];
	for (int i = 0; i < n; i++) {
		arr[i] = new long long int[soo + 1];
		if (i == 0) {
			for (int k = 0; k <= soo; k++) {
				arr[i][k] = 1;
			}
			continue;
		}
		for (int k = 0; k <= soo; k++) {
			if (k == 0) {
				arr[i][k] = 1;
				continue;
			}
			arr[i][k] = (arr[i - 1][k] + arr[i][k - 1])%1000000000;
		}
	}

	cout << arr[n - 1][soo];

}