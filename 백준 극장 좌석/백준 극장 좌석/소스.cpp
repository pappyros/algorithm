#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main() {
	int n, v;
	cin >> n >> v;
	vector<int>vip;
	int index = 0;
	int choi = 0;

	for (int i = 0; i < v; i++) {
		int a;
		cin >> a;
		int imsi = a - index-1;
		if (imsi == 0) {
			index = a;
			vip.push_back(1);
		}
		else if (imsi > choi) {
			choi = imsi;
			index = a;
			vip.push_back(imsi);
		}
		else {
			index = a;
			vip.push_back(imsi);

		}

	}
	if (n - index==0) {
		

	}
	else {
		vip.push_back(n - index);
	}
	int *fibo = new int[choi+2];
	fibo[0] = 1;
	fibo[1] = 2;
	
	sort(vip.begin(), vip.end());

	for (int i = 2; i < vip[vip.size()-1]; i++) {
		fibo[i] = fibo[i - 1] + fibo[i - 2];
	}
	int sum = 1;
	
	
	for (int i = 0; i < vip.size(); i++) {
		
		sum *= fibo[vip[i]-1];
	}
	cout << sum;
	
}