#include<iostream>
#include<vector>
#include<algorithm>
#include<functional>
using namespace std;

int main() {

	int tc;
	cin >> tc;
	vector<int>A;
	vector<int>B;
	for (int i = 0; i < tc; i++) {
		int aa;
		cin >> aa;
		A.push_back(aa);
	}
	for (int i = 0; i < tc; i++) {
		int aa;
		cin >> aa;
		B.push_back(aa);
	}
	sort(A.begin(), A.end());
	sort(B.begin(),B.end(),greater<int>());
	
	
	int sum = 0;
	for (int i = 0; i < tc; i++) {
		sum += A[i] * B[i];
	}
	cout << sum;

}