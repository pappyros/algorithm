#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int func(int current, vector<int> coin) {
	int toreturn = 0;
	vector<int>arr;

	for (int i = 0; i < coin.size(); i++) {
		int mok = current / coin[i];
		int nam = current%coin[i];
		if (nam == 0) {
			arr.push_back(mok);
				continue;
		};
		if (mok == 0)continue;

		int imsi =func(current - coin[i] * mok, coin);
		if (imsi == -1) continue;
		arr.push_back(imsi+mok);
		

	}
	if (arr.size() == 0) {
		return -1;
	}
	sort(arr.begin(), arr.end());
	return arr[0];
	
}

int main() {
	int n, money;

	cin >> n >> money;
	vector<int> coin;

	for (int i = 0; i < n; i++) {
		int won;
		cin >> won;
		coin.push_back(won);
	}
	cout << func(money, coin);

}