#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

/*
class dp {
public:
	
	vector<vector<int>>brr;
	
};

int main() {
	int n, k;
	cin >> n >> k;
	vector<int>coin;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		coin.push_back(a);
	}
	dp *dparr = new dp[k+1];
////////////////////////////
	for (int i = 1; i <= k; i++) {
		for (int p = 0; p < coin.size(); p++) {
			if (i == coin[p]) {
				vector<int> aaa;
				aaa.push_back(coin[p]);

				dparr[i].brr.push_back(aaa);

			}
			else if (i > coin[p]) {
				for (int q = 0; q < dparr[i - coin[p]].brr.size(); q++) {
					vector<int> aaa;
					aaa = dparr[i - coin[p]].brr[q];
					aaa.push_back(coin[p]);
					dparr[i].brr.push_back(aaa);
					
				}

			}
		}
		////////////////
		vector<int>imsi;
		imsi.push_back(-1);
		int result = 0;

		for (int s = 0; s < dparr[i].brr.size(); s++) {
			sort(dparr[i].brr[s].begin(), dparr[i].brr[s].end());
			if (imsi != dparr[i].brr[s]) {
				imsi = dparr[i].brr[s];
				result++;
			}
		}
		vector<vector<int>>res;
		for (int s = 0; s < dparr[i].brr.size(); s++) {
			if (s == 0) {
				res.push_back(dparr[i].brr[s]);

				continue;
			}
			for (int q = 0; q <= res.size(); q++) {
				if (q == res.size()) {
					res.push_back(dparr[i].brr[s]);
					break;

				}
				if (res[q] == dparr[i].brr[s]) {
					break;
				}

			}
		}
		dparr[i].brr = res;

	}
	
	cout << dparr[k].brr.size();

    

	


	

	
}*/

int main() {

	int n, k;
	cin >> n >> k;

	vector<int>coin;
	for (int i = 0; i < n; i++) {
		int won;
		cin >> won;
		coin.push_back(won);

	}
	int *dp = new int[k + 1];
	dp[0] = 1;
	for (int i = 1; i <= k; i++) {
		dp[i] = 0;
	}
	for (int i = 0; i < coin.size(); i++) {
		for (int p = 0; p <= k; p++) {
			if (p >= coin[i]) {
				dp[p] += dp[p - coin[i]];
			}
		}
	}
	cout << dp[k];



	
}