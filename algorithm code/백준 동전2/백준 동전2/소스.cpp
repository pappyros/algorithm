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


int dap = -1;
for (int i = 0; i < dparr[k].brr.size(); i++) {
	if (i == 0) {
		dap = dparr[k].brr[i].size();
		continue;
	}
	if (dap > dparr[k].brr[i].size()) {
		dap = dparr[k].brr[i].size();
	}
}
cout << dap;









}*/


int main() {

	int n, k;
	cin >> n >> k;
	int *dp = new int[k + 1];
	vector<int>coin;
	for (int i = 0; i < n; i++) {
		int won;
		cin >> won;
		coin.push_back(won);
	}

	for (int i = 0; i <= k; i++) {
		dp[i] = -1;
	}
	dp[0] = 0;

	for (int i = 1; i <= k; i++) {
		
		for (int p = 0; p < coin.size(); p++) {
			if (i == coin[p]) {
				dp[i] = 1;
				continue;
			}
			else if (i > coin[p]) {
				if (dp[i - coin[p]] == -1) {
					continue;
				}
				int won = 1 + dp[i - coin[p]];
				if (dp[i] == -1) {
					dp[i] = won;
				}
				else {
					if (dp[i] > won) {
						dp[i] = won;
					}
				}
			}

		}
	}

	
		cout << dp[k];
	

}