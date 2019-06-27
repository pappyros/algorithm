#include<iostream>
#include<vector>
using namespace std;

int main() {
	vector<int>sosu;
	vector<int>dp;
	sosu.push_back(0);
	dp.push_back(0);
	int gab;
	cin >> gab;
	for (int i = 2; i <= gab; i++) {
		int hope = 1;
		for (int k = i - 1; k > 1; k--) {
			if (i%k == 0) {
				hope = 0;
				break;
			}
		}
		if (hope == 1) {
			sosu.push_back(i);
			if (dp.size() == 0) {
				dp.push_back(i);
			}
			else {
				dp.push_back(i + dp[dp.size() - 2]);

			}
		}
		else {
			continue;

		}
	}
    
	int result = 0;
	for (int i = 1; i < sosu.size(); i++) {
		for()
		
		
	}



	

}


