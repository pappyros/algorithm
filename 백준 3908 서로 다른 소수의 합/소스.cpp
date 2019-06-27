#include<iostream>
#include<vector>
#include <cmath>
#include <vector>
#include <cstring>



using namespace std;

long int arr[2000][15];
long int imsi[2000][15];
void haha() {
	vector<long int>prr;
	arr[0][0] = 1;
	for (int i = 2; i <= 1120; i++) {
		bool t = true;
		for (int k = 2; k < i; k++) {
			if (i%k == 0) {
				t = false; break;
			}
		}
		if (t)prr.push_back(i);
	}

	for (int i = 0; i < prr.size(); i++) {
		for (int k = 0; k <1200; k++) {
			for (int p = 0; p < 15; p++) {
				if (p + 1 > 14 || arr[k][p] == 0)continue;
				imsi[k + prr[i]][p + 1] += arr[k][p];
			}
		}
		for (int k = 0; k < 2000; k++) {
			for (int p = 0; p < 15; p++) {
				arr[k][p] += imsi[k][p]; imsi[k][p] = 0;
			}
		}
	}
}
vector<int> cand;
const int MAXN = 1120;
bool isPrime[1121];
void eratosthenes() {
	memset(isPrime, 1, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
	int sqrtn = int(sqrt(MAXN));
	for (int i = 2; i <= sqrtn; ++i)
		if (isPrime[i])
			for (int j = i*i; j <= MAXN; j += i)
				isPrime[j] = false;
	for (int i = 2; i <= MAXN; ++i)
		if (isPrime[i]) cand.push_back(i);
}

int d[1130][15];



int main() {
	
	eratosthenes();
	int n = cand.size();

	d[0][0] = 1;
	for (int i = 0; i<n; ++i)
		for (int j = MAXN; j >= cand[i]; --j)
			for (int k = 1; k <= 14; ++k)
				d[j][k] += d[j - cand[i]][k - 1];
	
	haha();
   
	int aa; cin >> aa;
	vector<int>res;
	for (int i = 0; i < aa; i++) {
		int q, w; cin >> q >> w;
		res.push_back(d[q][w]);
	}
	for (int i = 0; i < aa; i++)cout << res[i] << endl;
}
